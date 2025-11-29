use zngur::Zngur;

fn main() {
    let _build = Zngur::from_zng_file("zng/lib.zng")
        .with_rs_file("src/zgenerated.rs")
        .with_h_file("zgenerated.h")
        .generate();

    println!("cargo::rerun-if-changed=src/lib.rs");
    println!("cargo::rerun-if-changed=zng/lib.zng");

    println!("cargo::rerun-if-changed=src/types.rs");
    println!("cargo::rerun-if-changed=src/types/*.rs");
    println!("cargo::rerun-if-changed=zng/types.zng");
    println!("cargo::rerun-if-changed=zng/types/*.zng");

    println!("cargo::rerun-if-changed=src/abstractions.rs");
    println!("cargo::rerun-if-changed=src/abstractions/*.rs");
    println!("cargo::rerun-if-changed=zng/abstractions.zng");
    println!("cargo::rerun-if-changed=zng/abstractions/*.zng");
}
