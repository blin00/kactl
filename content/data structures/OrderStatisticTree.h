/**
 * Author: Simon Lindholm
 * Date: 2016-03-22
 * Source: hacKIT, NWERC 2015
 * Description: A set (not multiset!) with support for finding the n'th
 * element, and finding the index of an element in $O(\log N)$ time.
 */
#pragma once

#include <iostream>
#include <map>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> /** keep-include */
#include <ext/pb_ds/tree_policy.hpp> /** keep-include */
using namespace __gnu_pbds;

template <class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag,
	  tree_order_statistics_node_update>;

int main() {
	Tree<int> t;
	t.insert(8);
	auto it = t.insert(10).first;
	assert(it == t.lower_bound(9));
	assert(t.order_of_key(10) == 1);
	assert(t.order_of_key(11) == 2);
	assert(*t.find_by_order(0) == 8);
}