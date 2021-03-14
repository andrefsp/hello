#include "http_client.h"

#include "response.c"
#include "request.c"
#include "string_utils.c"


static size_t _responseBodyHandler(void *contents, size_t size, size_t nmemb, void *userp) {
    Response *res = userp;
    res->WriteBody(res, (char *)contents);
    return nmemb;
}

static size_t _responseHeaderHandler(void *contents, size_t size, size_t nmemb, void *userp) {
    char **parts = GC_MALLOC(0);
    char *header = GC_MALLOC(nmemb*sizeof(char));

    strcpy(header, contents);
    header = str_clean(header);

    if (strlen(header) < 1) {
        return nmemb;
    }

    Response *res = (Response *)userp;
    if (!res->StatusCode) {
        // TODO(andrefsp): Validate status header.
        // There should be an error in case an invalid status header is sent
        parts = str_tokenize(header, " ");
        res->SetStatusCode(res, atoi(parts[1]));
        res->SetStatus(res, parts[2]);
    } else {
        parts = str_n_tokenize(header, ":", 1);
        char *hname = str_strip(parts[0], ' ');
        char *hval = str_strip(parts[1], ' ');

        res->SetHeader(res, hname, hval); 
    }

    return nmemb;
}


Response *HttpClient_Do(HttpClient *c, Request *r) {
    // No progress
    curl_easy_setopt(c->curl, CURLOPT_NOPROGRESS, 1L);
    curl_easy_setopt(c->curl, CURLOPT_TIMEOUT, r->Timeout);
    curl_easy_setopt(c->curl, CURLOPT_CONNECTTIMEOUT, r->ConnectTimeout);

    // Method
    curl_easy_setopt(c->curl, CURLOPT_CUSTOMREQUEST, r->Method);

    // Url
    curl_easy_setopt(c->curl, CURLOPT_URL, r->Url);

    // Body 
    curl_easy_setopt(c->curl, CURLOPT_POSTFIELDS, r->Body);

    // Headers
    for (int i = 0; i < r->Headers->Size; i++) {
        char *name = r->Headers->Items[i]->key;
        char *val = r->Headers->Items[i]->data;

        char *header = GC_MALLOC((strlen(name)+strlen(val)+4)*sizeof(char));
        header = strcat(header, name);
        header = strcat(header, ": ");
        header = strcat(header, val);
        
        c->chunk = curl_slist_append(c->chunk, header);
        curl_easy_setopt(c->curl, CURLOPT_HTTPHEADER, c->chunk);
    }

    Response *res = NewResponse();

    curl_easy_setopt(c->curl, CURLOPT_HEADERFUNCTION, _responseHeaderHandler);
    curl_easy_setopt(c->curl, CURLOPT_WRITEFUNCTION, _responseBodyHandler);
    curl_easy_setopt(c->curl, CURLOPT_HEADERDATA, res);
    curl_easy_setopt(c->curl, CURLOPT_WRITEDATA, res);

    curl_easy_perform(c->curl);

    return res;
}


HttpClient *NewHttpClient() {
    HttpClient *c = GC_MALLOC(sizeof(HttpClient));

    c->curl = curl_easy_init();
    c->chunk = NULL;

    c->Do = HttpClient_Do;
    return c;
}

