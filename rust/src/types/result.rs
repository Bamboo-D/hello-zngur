pub fn is_positive_result(input: i32) -> Result<String, i32> {
    if input > 0 {
        Ok(format!("{} > 0", input))
    } else {
        Err(-1)
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_result_ok() {
        let res = is_positive_result(42);
        assert!(res.is_ok());
        assert_eq!(res.unwrap(), "42 > 0");
    }

    #[test]
    fn test_result_err() {
        let res = is_positive_result(0);
        assert!(res.is_err());
        assert_eq!(res.unwrap_err(), -1);
    }
}
