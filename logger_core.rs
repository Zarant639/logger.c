// logger_core.rs
fn main {
    
}
#[no_mangle]
pub extern "C" fn is_valid_age(age: i32) -> bool {
    if age >= 0 && age <= 127 {
        return true;
    }   else {
        return false;
    }
}
}