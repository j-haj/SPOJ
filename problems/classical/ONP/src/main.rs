use std::collections::LinkedList;
use std::io;

/// Implements the [Shunting-yard](https://en.wikipedia.org/wiki/Shunting-yard_algorithm)
/// algorithm. The basic idea is to maintain an output queue and and operator
/// stack. Depending on the operator read, either add to the stack or add to the
/// output queue. All number tokens get pushed to the output queue.
///
/// # Arguments
///
/// * `expr` - A string slice that holds the expression to be parsed.
///
/// # Example
/// `expr` = "a + (b * c)"
/// the output of `postifx_to_infix(expr)` would be:
/// "abc*+"
fn postifx_to_infix<'a>(expr: &'a str) -> &'a str {
    let mut output_queue = LinkedList::new();
    let mut operator_stack = LinkedList::new();

    for c in expr.chars() {
        match c {
            '+' => println!("plus"),
            '-' => continue,
            '/' => continue,
            '*' => continue,
            '^' => continue,
            '(' => operator_stack.push_back(c),
            ')' => continue,
            _ if c.is_alphabetic() => output_queue.push_back(c),
            _ => panic!("Encountered unknown character"),
        }
        println!("Character {}", &c);
    }
    "output"
}

fn main() {
    let s = String::from("a + (b * c)");
    let output = postifx_to_infix(&s);
    println!("Result: {}", output);
}
