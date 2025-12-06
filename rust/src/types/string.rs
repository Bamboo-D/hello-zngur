pub fn sample_string() -> String {
    "Hi, Z!".to_string()
}

pub fn echo_string(s: String) -> String {
    s
}

pub fn reverse_string(s: &mut String) {
    let reversed: String = s.chars().rev().collect();
    *s = reversed;
}

pub fn reverse_str(s: &str) -> String {
    s.chars().rev().collect()
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_sample_string() {
        let s = sample_string();
        assert_eq!(s, "Hi, Z!");
    }

    #[test]
    fn test_echo_string() {
        let s = "Hello, World!".to_string();
        let echoed = echo_string(s.clone());
        assert_eq!(echoed, s);
    }

    #[test]
    fn test_reverse_string() {
        let mut s = "一二三四五".to_string();
        reverse_string(&mut s);
        assert_eq!(s, "五四三二一");
    }

    #[test]
    fn test_reverse_str() {
        let s = "12345";
        let reversed = reverse_str(s);
        assert_eq!(reversed, "54321");
    }
}
