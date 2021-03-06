#include "MemberExpression.h"
#include "../util.h"

void MemberExpression::parse() {
    memberInfo = decoders::d_ref(reader);
    objInfo = decoders::d_node(reader);
}

string MemberExpression::to_string() {
    string result = (objInfo == nullptr ? "" : objInfo->to_string());

    if (decoders::is_integer(result) || (objInfo->type() == NodeType::BinaryExpression)) {
        result = '(' + result + ')';
    }

    // Check member validity...
    if (decoders::valid_id(memberInfo.id)) {
        result += '.' + utils::to_string(memberInfo.id);
    } else {
        result += '[';
        // check if ID can be converted to an integer...
        if(decoders::is_integer(memberInfo.id)) {
            result += utils::to_string(memberInfo.id);
        } else {
            result += utils::to_string_literal(memberInfo.id);
        }
        result += ']';
    }

    return result;
}

