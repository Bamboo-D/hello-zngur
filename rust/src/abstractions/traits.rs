// 为 (usize, f32) 实现一个自定义 trait 用于提取成员

pub trait MyGetTuple {
    fn index(&self) -> usize;
    fn score(&self) -> f32;
}

impl MyGetTuple for (usize, f32) {
    fn index(&self) -> usize {
        self.0
    }

    fn score(&self) -> f32 {
        self.1
    }
}

pub fn sample_tuple() -> (usize, f32) {
    (0, 0.88)
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_sample_tuple() {
        let t = sample_tuple();
        assert_eq!(t.index(), 0);
        assert_eq!(t.score(), 0.88);
    }
}
