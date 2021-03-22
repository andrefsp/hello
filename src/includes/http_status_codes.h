#ifndef _HELLO_HTTP_STATUS_CODES_H
#define _HELLO_HTTP_STATUS_CODES_H

typedef struct HttpStatusCode {
    char *Status;
    int Code;
} HttpStatusCode;


typedef struct HttpStatusCodes {
    HttpStatusCode    *HttpContinue;
    HttpStatusCode    *HttpSwitchingProtocols;
    HttpStatusCode    *HttpProcessing;
    HttpStatusCode    *HttpEarlyHints;


    HttpStatusCode    *HttpOK;
    HttpStatusCode    *HttpCreated;
    HttpStatusCode    *HttpAccepted;
    HttpStatusCode    *HttpNonAuthoritativeInfo;
    HttpStatusCode    *HttpNoContent;
    HttpStatusCode    *HttpResetContent;
    HttpStatusCode    *HttpPartialContent;
    HttpStatusCode    *HttpMultiStatus;
    HttpStatusCode    *HttpAlreadyReported;
    HttpStatusCode    *HttpIMUsed;


    HttpStatusCode    *HttpMultipleChoices;
    HttpStatusCode    *HttpMovedPermanently;
    HttpStatusCode    *HttpFound;
    HttpStatusCode    *HttpSeeOther;
    HttpStatusCode    *HttpNotModified;
    HttpStatusCode    *HttpUseProxy;
    HttpStatusCode    *HttpTemporaryRedirect;
    HttpStatusCode    *HttpPermanentRedirect;


    HttpStatusCode    *HttpBadRequest;
    HttpStatusCode    *HttpUnauthorized;
    HttpStatusCode    *HttpPaymentRequired;
    HttpStatusCode    *HttpForbidden;
    HttpStatusCode    *HttpNotFound;
    HttpStatusCode    *HttpMethodNotAllowed;
    HttpStatusCode    *HttpNotAcceptable;
    HttpStatusCode    *HttpProxyAuthRequired;
    HttpStatusCode    *HttpRequestTimeout;
    HttpStatusCode    *HttpConflict;
    HttpStatusCode    *HttpGone;
    HttpStatusCode    *HttpLengthRequired;
    HttpStatusCode    *HttpPreconditionFailed;
    HttpStatusCode    *HttpRequestEntityTooLarge;
    HttpStatusCode    *HttpRequestURITooLong;
    HttpStatusCode    *HttpUnsupportedMediaType;
    HttpStatusCode    *HttpRequestedRangeNotSatisfiable;
    HttpStatusCode    *HttpExpectationFailed;
    HttpStatusCode    *HttpTeapot;
    HttpStatusCode    *HttpMisdirectedRequest;
    HttpStatusCode    *HttpUnprocessableEntity;
    HttpStatusCode    *HttpLocked;
    HttpStatusCode    *HttpFailedDependency;
    HttpStatusCode    *HttpTooEarly;
    HttpStatusCode    *HttpUpgradeRequired;
    HttpStatusCode    *HttpPreconditionRequired;
    HttpStatusCode    *HttpTooManyRequests;
    HttpStatusCode    *HttpRequestHeaderFieldsTooLarge;
    HttpStatusCode    *HttpUnavailableForLegalReasons;


    HttpStatusCode    *HttpInternalServerError;
    HttpStatusCode    *HttpNotImplemented;
    HttpStatusCode    *HttpBadGateway;
    HttpStatusCode    *HttpServiceUnavailable;
    HttpStatusCode    *HttpGatewayTimeout;
    HttpStatusCode    *HttpHTTPVersionNotSupported;
    HttpStatusCode    *HttpVariantAlsoNegotiates;
    HttpStatusCode    *HttpInsufficientStorage;
    HttpStatusCode    *HttpLoopDetected;
    HttpStatusCode    *HttpNotExtended;
    HttpStatusCode    *HttpNetworkAuthenticationRequired;
} HttpStatusCodes;


HttpStatusCodes codes;


HttpStatusCode *NewStatusCode();

#endif
