use std::iter::once;
use itertools::Itertools;

fn main() {
    let number_pair = vec![ (1, 4), (2, 3), (3, 9)];
    println!("{:?}", number_pair);
    //let flatten_and_unique = number_pair.into_iter().flatten().collect::<Vec<i32>>();
    // https://users.rust-lang.org/t/flattening-a-vector-of-tuples/11409/3
    let flatten = number_pair
                                        .iter()
                                        .flat_map(|tup| once(tup.0).chain(once(tup.1)))
                                        .collect::<Vec<i32>>();
    println!("{:?}", flatten);
    let mut flatten_and_sorted: Vec<i32> = flatten.clone();
    flatten_and_sorted.sort();
    // https://stackoverflow.com/questions/47636618/vecdedup-does-not-work-how-do-i-deduplicate-a-vector-of-strings
    let flatten_and_sorted = flatten_and_sorted.into_iter().unique().collect::<Vec<i32>>();
    println!("{:?}", flatten_and_sorted);

    // and in oneshot
    let flatten2 = number_pair
                                    .iter()
                                    .flat_map(|tup| once(tup.0).chain(once(tup.1)))
                                    .sorted()
                                    .into_iter()
                                    .unique()
                                    .collect::<Vec<i32>>();
    println!("flatten2: {:?}", flatten2);
}
