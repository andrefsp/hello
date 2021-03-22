#ifndef _HELLO_HTTP_STATUS_CODES_C
#define _HELLO_HTTP_STATUS_CODES_C


HttpStatusCode     HttpContinue                          = {"Continue", 100};                      // RFC 7231, 6.2.1
HttpStatusCode     HttpSwitchingProtocols                = {"SwitchingProtocols", 101};            // RFC 7231, 6.2.2
HttpStatusCode     HttpProcessing                        = {"Processing", 102};                    // RFC 2518, 10.1
HttpStatusCode     HttpEarlyHints                        = {"EarlyHints", 103};                    // RFC 8297


HttpStatusCode     HttpOK                                = {"OK", 200};                            // RFC 7231, 6.3.1
HttpStatusCode     HttpCreated                           = {"Created", 201};                       // RFC 7231, 6.3.2
HttpStatusCode     HttpAccepted                          = {"Accepted", 202};                      // RFC 7231, 6.3.3
HttpStatusCode     HttpNonAuthoritativeInfo              = {"NonAuthoritativeInfo", 203};          // RFC 7231, 6.3.4
HttpStatusCode     HttpNoContent                         = {"NoContent", 204};                     // RFC 7231, 6.3.5
HttpStatusCode     HttpResetContent                      = {"ResetContent", 205};                  // RFC 7231, 6.3.6
HttpStatusCode     HttpPartialContent                    = {"PartialContent", 206};                // RFC 7233, 4.1
HttpStatusCode     HttpMultiStatus                       = {"MultiStatus", 207};                   // RFC 4918, 11.1
HttpStatusCode     HttpAlreadyReported                   = {"AlreadyReported", 208};               // RFC 5842, 7.1
HttpStatusCode     HttpIMUsed                            = {"IMUsed", 226};                        // RFC 3229, 10.4.1


HttpStatusCode     HttpMultipleChoices                   = {"MultipleChoices", 300};               // RFC 7231, 6.4.1
HttpStatusCode     HttpMovedPermanently                  = {"MovedPermanently", 301};              // RFC 7231, 6.4.2
HttpStatusCode     HttpFound                             = {"Found", 302};                         // RFC 7231, 6.4.3
HttpStatusCode     HttpSeeOther                          = {"SeeOther", 303};                      // RFC 7231, 6.4.4
HttpStatusCode     HttpNotModified                       = {"NotModified", 304};                   // RFC 7232, 4.1
HttpStatusCode     HttpUseProxy                          = {"UseProxy", 305};                      // RFC 7231, 6.4.5
HttpStatusCode     HttpTemporaryRedirect                 = {"TemporaryRedirect", 307};             // RFC 7231, 6.4.7
HttpStatusCode     HttpPermanentRedirect                 = {"PermanentRedirect", 308};             // RFC 7538, 3


HttpStatusCode     HttpBadRequest                        = {"BadRequest", 400};                    // RFC 7231, 6.5.1
HttpStatusCode     HttpUnauthorized                      = {"Unauthorized", 401};                  // RFC 7235, 3.1
HttpStatusCode     HttpPaymentRequired                   = {"PaymentRequired", 402};               // RFC 7231, 6.5.2
HttpStatusCode     HttpForbidden                         = {"Forbidden", 403};                     // RFC 7231, 6.5.3
HttpStatusCode     HttpNotFound                          = {"NotFound", 404};                      // RFC 7231, 6.5.4
HttpStatusCode     HttpMethodNotAllowed                  = {"MethodNotAllowed", 405};              // RFC 7231, 6.5.5
HttpStatusCode     HttpNotAcceptable                     = {"NotAcceptable", 406};                 // RFC 7231, 6.5.6
HttpStatusCode     HttpProxyAuthRequired                 = {"ProxyAuthRequired", 407};             // RFC 7235, 3.2
HttpStatusCode     HttpRequestTimeout                    = {"RequestTimeout", 408};                // RFC 7231, 6.5.7
HttpStatusCode     HttpConflict                          = {"Conflict", 409};                      // RFC 7231, 6.5.8
HttpStatusCode     HttpGone                              = {"Gone", 410};                          // RFC 7231, 6.5.9
HttpStatusCode     HttpLengthRequired                    = {"LengthRequired", 411};                // RFC 7231, 6.5.10
HttpStatusCode     HttpPreconditionFailed                = {"PreconditionFailed", 412};            // RFC 7232, 4.2
HttpStatusCode     HttpRequestEntityTooLarge             = {"RequestEntityTooLarge", 413};         // RFC 7231, 6.5.11
HttpStatusCode     HttpRequestURITooLong                 = {"RequestURITooLong", 414};             // RFC 7231, 6.5.12
HttpStatusCode     HttpUnsupportedMediaType              = {"UnsupportedMediaType", 415};          // RFC 7231, 6.5.13
HttpStatusCode     HttpRequestedRangeNotSatisfiable      = {"RequestedRangeNotSatisfiable", 416};  // RFC 7233, 4.4
HttpStatusCode     HttpExpectationFailed                 = {"ExpectationFailed", 417};             // RFC 7231, 6.5.14
HttpStatusCode     HttpTeapot                            = {"Teapot", 418};                        // RFC 7168, 2.3.3
HttpStatusCode     HttpMisdirectedRequest                = {"MisdirectedRequest", 421};            // RFC 7540, 9.1.2
HttpStatusCode     HttpUnprocessableEntity               = {"UnprocessableEntity", 422};           // RFC 4918, 11.2
HttpStatusCode     HttpLocked                            = {"Locked", 423};                        // RFC 4918, 11.3
HttpStatusCode     HttpFailedDependency                  = {"FailedDependency", 424};              // RFC 4918, 11.4
HttpStatusCode     HttpTooEarly                          = {"TooEarly", 425};                      // RFC 8470, 5.2.
HttpStatusCode     HttpUpgradeRequired                   = {"UpgradeRequired", 426};               // RFC 7231, 6.5.15
HttpStatusCode     HttpPreconditionRequired              = {"PreconditionRequired", 428};          // RFC 6585, 3
HttpStatusCode     HttpTooManyRequests                   = {"TooManyRequests", 429};               // RFC 6585, 4
HttpStatusCode     HttpRequestHeaderFieldsTooLarge       = {"RequestHeaderFieldsTooLarge", 431};   // RFC 6585, 5
HttpStatusCode     HttpUnavailableForLegalReasons        = {"UnavailableForLegalReasons", 451};    // RFC 7725, 3


HttpStatusCode     HttpInternalServerError               = {"InternalServerError", 500};           // RFC 7231, 6.6.1
HttpStatusCode     HttpNotImplemented                    = {"NotImplemented", 501};                // RFC 7231, 6.6.2
HttpStatusCode     HttpBadGateway                        = {"BadGateway", 502};                    // RFC 7231, 6.6.3
HttpStatusCode     HttpServiceUnavailable                = {"ServiceUnavailable", 503};            // RFC 7231, 6.6.4
HttpStatusCode     HttpGatewayTimeout                    = {"GatewayTimeout", 504};                // RFC 7231, 6.6.5
HttpStatusCode     HttpHTTPVersionNotSupported           = {"HTTPVersionNotSupported", 505};       // RFC 7231, 6.6.6
HttpStatusCode     HttpVariantAlsoNegotiates             = {"VariantAlsoNegotiates", 506};         // RFC 2295, 8.1
HttpStatusCode     HttpInsufficientStorage               = {"InsufficientStorage", 507};           // RFC 4918, 11.5
HttpStatusCode     HttpLoopDetected                      = {"LoopDetected", 508};                  // RFC 5842, 7.2
HttpStatusCode     HttpNotExtended                       = {"NotExtended", 510};                   // RFC 2774, 7
HttpStatusCode     HttpNetworkAuthenticationRequired     = {"NetworkAuthenticationRequired", 511}; // RFC 6585, 6


HttpStatusCodes codes = {
    &HttpContinue, 
    &HttpSwitchingProtocols, 
    &HttpProcessing, 
    &HttpEarlyHints, 
                                    
                                   
    &HttpOK, 
    &HttpCreated, 
    &HttpAccepted, 
    &HttpNonAuthoritativeInfo, 
    &HttpNoContent, 
    &HttpResetContent, 
    &HttpPartialContent, 
    &HttpMultiStatus, 
    &HttpAlreadyReported, 
    &HttpIMUsed, 
                                    
                                    
    &HttpMultipleChoices, 
    &HttpMovedPermanently, 
    &HttpFound, 
    &HttpSeeOther, 
    &HttpNotModified, 
    &HttpUseProxy, 
    &HttpTemporaryRedirect, 
    &HttpPermanentRedirect, 
                                    
                                   
    &HttpBadRequest, 
    &HttpUnauthorized, 
    &HttpPaymentRequired, 
    &HttpForbidden, 
    &HttpNotFound, 
    &HttpMethodNotAllowed, 
    &HttpNotAcceptable, 
    &HttpProxyAuthRequired, 
    &HttpRequestTimeout, 
    &HttpConflict, 
    &HttpGone, 
    &HttpLengthRequired, 
    &HttpPreconditionFailed, 
    &HttpRequestEntityTooLarge, 
    &HttpRequestURITooLong, 
    &HttpUnsupportedMediaType, 
    &HttpRequestedRangeNotSatisfiable, 
    &HttpExpectationFailed, 
    &HttpTeapot, 
    &HttpMisdirectedRequest, 
    &HttpUnprocessableEntity, 
    &HttpLocked, 
    &HttpFailedDependency, 
    &HttpTooEarly, 
    &HttpUpgradeRequired, 
    &HttpPreconditionRequired, 
    &HttpTooManyRequests, 
    &HttpRequestHeaderFieldsTooLarge, 
    &HttpUnavailableForLegalReasons, 
                                     
                                    
    &HttpInternalServerError, 
    &HttpNotImplemented, 
    &HttpBadGateway, 
    &HttpServiceUnavailable, 
    &HttpGatewayTimeout, 
    &HttpHTTPVersionNotSupported, 
    &HttpVariantAlsoNegotiates, 
    &HttpInsufficientStorage, 
    &HttpLoopDetected, 
    &HttpNotExtended, 
    &HttpNetworkAuthenticationRequired
};

#endif
