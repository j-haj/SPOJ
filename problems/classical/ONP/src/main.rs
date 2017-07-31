use std::collections::{BTreeMap, LinkedList};
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
    let mut output = String::from("");
    let mut operator_stack = LinkedList::new();

    let mut operator_prec = BTreeMap::new();
    operator_prec.insert('(', 4);
    operator_prec.insert('^', 3);
    operator_prec.insert('/', 2);
    operator_prec.insert('*', 2);
    operator_prec.insert('+', 1);
    operator_prec.insert('-', 1);

    for &c in expr.chars() {
        match c {
            Ok(c) if operator_prec.contains_key(c) => {
                while operator_prec[operator_stack.front()] > operator_prec[c] {
                    output.push(operator_stack.pop_front());
                }
                operator_stack.push_front(c);
            },
            Ok(c) if c.is_alphabetic() => output.push(c),
            Ok('(') => operator_stack.push_back('('),
            Ok(')') => {
                while operator_stack.front() != '(' {
                    output.push(operator_stack.pop_front());
                }
                operator_stack.pop_front();
            },
            _ => panic!("Encountered unknown character"),
        }
    }
    output.as_str()
}

fn main() {
    let s = String::from("a + (b * c)");
    let output = postifx_to_infix(&s);
    println!("Result: {}", output);
}
