A collection of boilerplate code to help you start your journey with [Zngur](https://github.com/HKalbasi/zngur).

Demonstrates how to call Rust from C++ (using Rust as a library) with a CMake build system.

---

# Hello, Zngur!

## Sample

### Basic types

- [x] Vec (`Vec<i32>`<->`std::vector<int32_t>`)
- [x] Vec Vec (`Vec<Vec<f32>>`<->`std::vector<std::vector<float>>`)
- [x] &str (`&str`<->`std::string_view`)
- [x] String (`String`<->`&str`<->`std::string_view`<->`std::string`)
- [ ] Result

### Abstractions

- [x] traits (+ tuple)
- [ ] external crates

### Examples

- [ ] bm25 + jieba-rs

---

Zngur 又好又强大又优雅。将胶水代码限制在 C++ 中、几乎不预设开发者行为——使它能做到一些 cxx 做不到的事，也更适配（且高效）于向旧 C++ 项目引入 Rust 能力（库）的实际场景。

极少的内置桥接方法是 Zngur 的优点也是门槛，因此个人在这里写下一些可复用的实践以供参考。
