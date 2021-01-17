#ifndef LEPTJSON_H__
#define LEPTJSON_H__

typedef enum { LEPT_NULL, LEPT_FALSE, LEPT_TRUE, LEPT_NUMBER, LEPT_STRING, LEPT_ARRAY, LEPT_OBJECT } lept_type;

typedef struct {
    double n;
    lept_type type;
}lept_value;

enum {
    LEPT_PARSE_OK = 0,              //没有错误
    LEPT_PARSE_EXPECT_VALUE,        //json只含有空白
    LEPT_PARSE_INVALID_VALUE,       //其他情况
    LEPT_PARSE_ROOT_NOT_SINGULAR,   //空白之后还有其他字符
    LEPT_PARSE_NUMBER_TOO_BIG       //
};

int lept_parse(lept_value* v, const char* json);

lept_type lept_get_type(const lept_value* v);

double lept_get_number(const lept_value* v);

#endif /* LEPTJSON_H__ */
