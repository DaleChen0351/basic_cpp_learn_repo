#pragma once

template <typename T>
void containerAllInterface(T& a, T&b) {
	T c;
	// copy ctor
	T d(a);
	T e = a;
	T f(std::move(a));

	// iter
	auto iterB = b.begin();
	auto iterE = b.end();
	T g(iterB, iterE);
	b.size();
	b.empty(); // exccept forward_list
	if (b == c)
	{

	}
	if (b<c) // except unordered_map/set
	{

	}
	// copy assign
	e = b;
	e = std::move(b);
	e.swap(g);
	std::swap(e, g);

	// const &
	auto ea = e.cbegin();
	// *ea;// const& ?
    // clear
	e.clear(); // except array
}