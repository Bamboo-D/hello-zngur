#include "types/string.hpp"

#include <cassert>

using namespace rust::serde_json;
using namespace rust::crate::abstractions;

int main()
{
	auto json_str_rust = R"({"name": "John", "age": 30})"_rs;
	auto json_rust_result = from_str(json_str_rust);
	assert(json_rust_result.is_ok());

	auto json_rust = json_rust_result.unwrap();
	remove_key_from_json(json_rust, "age"_rs);

	auto after_json_string_rust_result = to_string(json_rust);
	assert(after_json_string_rust_result.is_ok());
	auto after_json_string_rust = after_json_string_rust_result.unwrap();
	auto after_json_string_cpp = intoCpp<std::string>(std::move(after_json_string_rust));
	assert(after_json_string_cpp == R"({"name":"John"})");
}
