#ifndef __NACOS_EXCEPTIONS_H_
#define __NACOS_EXCEPTIONS_H_

#include <exception>
#include "NacosString.h"
#include "Compatibility.h"

namespace nacos{
class NacosException : public std::exception {
protected:
    int _errcode;
    NacosString _errmsg;
public:
    NacosException(int errorcode, const char *errormsg) NACOS_NOTHROW();

    NacosException(int errorcode, const NacosString &errormsg) NACOS_NOTHROW();

    ~NacosException() NACOS_NOTHROW() {};

    const char *what() const NACOS_NOTHROW() { return _errmsg.c_str(); };

    const int errorcode() const NACOS_NOTHROW() { return _errcode; };

    static const int CLIENT_INVALID_PARAM = -400;
    /**
    * over client threshold（超过server端的限流阈值）
    */
    static const int CLIENT_OVER_THRESHOLD = -503;

    /**
    * server error code
    * 400 403 throw exception to user
    * 500 502 503 change ip and retry
    */

    /**
    * invalid param（参数错误）
    */
    static const int INVALID_PARAM = 400;
    /**
    * no right（鉴权失败）
    */
    static const int NO_RIGHT = 403;

    static const int HTTP_NOT_FOUND = 404;

    /**
    * conflict（写并发冲突）
    */
    static const int CONFLICT = 409;
    /**
    * server error（server异常，如超时）
    */
    static const int SERVER_ERROR = 500;
    /**
    * bad gateway（路由异常，如nginx后面的Server挂掉）
    */
    static const int BAD_GATEWAY = 502;
    /**
    * over threshold（超过server端的限流阈值）
    */
    static const int OVER_THRESHOLD = 503;

    /**
    * Error while parsing the JSON string
    */
    static const int INVALID_JSON_FORMAT = 100001;

    /**
    * One or more JSON field is missing
    */
    static const int LACK_JSON_FIELD = 100002;

    static const int MALFORMED_CONFIG_FILE = 1001;
    static const int FILE_NOT_FOUND = 1002;
    static const int INVALID_FACTORY_CONFIG = 1003;
    static const int ALL_SERVERS_TRIED_AND_FAILED = 1004;
    static const int NO_SERVER_AVAILABLE = 1005;
    static const int INVALID_LOGIN_CREDENTIAL = 1006;
    static const int UNABLE_TO_OPEN_FILE = 1007;
    static const int UNABLE_TO_GET_HOST_IP = 1008;
    static const int UNABLE_TO_CREATE_SOCKET = 1009;
    static const int INVALID_CONFIG_PARAM = 1010;
    static const int UNABLE_TO_GET_HOST_NAME = 1011;

};

class NetworkException : public std::exception {
private:
    int _curlerrcode;
    NacosString _errmsg;
public:
    NetworkException(int errorcode, const char *errormsg) NACOS_NOTHROW(): _curlerrcode(errorcode), _errmsg(errormsg) {};

    NetworkException(int errorcode, const NacosString &errormsg) NACOS_NOTHROW(): _curlerrcode(errorcode), _errmsg(errormsg) {};

    ~NetworkException() NACOS_NOTHROW() {};

    const char *what() const NACOS_NOTHROW() { return _errmsg.c_str(); };

    const int errorcode() const NACOS_NOTHROW() { return _curlerrcode; };
};

class IOException : public NacosException {
public:
    IOException(int errorcode, const char *errormsg) NACOS_NOTHROW() : NacosException(errorcode, errormsg) {};

    IOException(int errorcode, const NacosString &errormsg) NACOS_NOTHROW() : NacosException(errorcode, errormsg) {};

    ~IOException() NACOS_NOTHROW() {};
};

class MalformedConfigException : public NacosException {
public:
    MalformedConfigException(const NacosString &file, const NacosString &detailedMsg) : NacosException(NacosException::MALFORMED_CONFIG_FILE,
                                                                       "Malformed Config file:" + file + " reason:" + detailedMsg) {};
};

class InvalidFactoryConfigException : public NacosException {
public:
    InvalidFactoryConfigException() : NacosException(NacosException::INVALID_FACTORY_CONFIG,
                                                     "Either config file or property should be configed.") {};
};
}//namespace nacos

#endif
