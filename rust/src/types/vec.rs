pub fn sample_vec() -> Vec<i32> {
    vec![1, 2, 3, 4, 5]
}

pub fn echo_vec(v: Vec<i32>) -> Vec<i32> {
    v
}

pub fn reverse_vec(v: &mut Vec<i32>) {
    v.reverse();
}

pub fn sample_2d_vec() -> Vec<Vec<f32>> {
    vec![vec![1.0, 2.0, 3.0], vec![4.0, 5.0, 6.0]]
}

pub fn echo_2d_vec(v: Vec<Vec<f32>>) -> Vec<Vec<f32>> {
    v
}

pub fn square_2d_vec(v: &mut Vec<Vec<f32>>) {
    for inner_vec in v.iter_mut() {
        for val in inner_vec.iter_mut() {
            *val = (*val) * (*val);
        }
    }
}

pub fn print_2d_vec(vec: &Vec<Vec<f32>>) {
    for inner_vec in vec {
        let formatted: Vec<String> = inner_vec.iter().map(|&f| format!("{:.3}", f)).collect();
        println!("{}", formatted.join(", "));
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_sample_vec() {
        let v = sample_vec();
        assert_eq!(v, vec![1, 2, 3, 4, 5]);
    }

    #[test]
    fn test_echo_vec() {
        let v = vec![1, 2, 3];
        let echoed = echo_vec(v.clone());
        assert_eq!(echoed, v);
    }

    #[test]
    fn test_reverse_vec() {
        let mut v = vec![1, 2, 3];
        reverse_vec(&mut v);
        assert_eq!(v, vec![3, 2, 1]);
    }

    #[test]
    fn test_sample_2d_vec() {
        let v = sample_2d_vec();
        assert_eq!(v, vec![vec![1.0, 2.0, 3.0], vec![4.0, 5.0, 6.0]]);
    }

    #[test]
    fn test_echo_2d_vec() {
        let v = vec![vec![1.0, 2.0, 3.0], vec![4.0, 5.0, 6.0]];
        let echoed = echo_2d_vec(v.clone());
        assert_eq!(echoed, v);
    }

    #[test]
    fn test_square_2d_vec() {
        let mut v = vec![vec![1.0, 2.0], vec![3.0, 4.0]];
        square_2d_vec(&mut v);
        assert_eq!(v, vec![vec![1.0, 4.0], vec![9.0, 16.0]]);
    }
}
