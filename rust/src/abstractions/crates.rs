use serde_json::Value;

pub fn remove_key_from_json(json_obj: &mut Value, key: &str) {
    if let Value::Object(map) = json_obj {
        map.remove(key);
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use serde_json::{from_str, to_string};

    #[test]
    fn test_string_to_json() {
        let json_str = r#"{"name": "John", "age": 30}"#;
        let json_obj: Result<Value, _> = from_str(json_str);
        assert!(json_obj.is_ok());
        assert_eq!(
            json_obj.unwrap(),
            serde_json::json!({"name": "John", "age": 30})
        );
    }

    #[test]
    fn test_json_to_string() {
        let json_obj = serde_json::json!({"name": "John", "age": 30});
        let json_str = to_string(&json_obj);
        assert!(json_str.is_ok());
        let result = json_str.unwrap();
        assert!(result == r#"{"name":"John","age":30}"# || result == r#"{"age":30,"name":"John"}"#);
    }

    #[test]
    fn test_remove_key_from_json() {
        let mut json_obj = serde_json::json!({"name": "John", "age": 30});
        remove_key_from_json(&mut json_obj, "age");
        assert_eq!(json_obj, serde_json::json!({"name": "John"}));
    }
}
