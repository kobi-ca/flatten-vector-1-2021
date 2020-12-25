#include <iostream>
#include <vector>
#include <algorithm>

#include <range/v3/all.hpp>

// https://twitter.com/levynoise/status/1341858200988102657
// San Diego C++ meetup 1/12/2021

int main(){
    const std::vector<std::pair<int,int>> number_pair { {1,4},{2,3},{3,9} };
    {
        // using plain loop
        std::vector<int> out;
        // if we use p as pair, then using p.first, p.second
        // but using C++17 structure binding is shorter
        std::clog << "loop\n\t";
        for (const auto [k,v] : number_pair) {
            out.push_back(k);
            out.push_back(v);
        }
        for(const auto e : out) {
            std::clog << e << ' ';
        }
        std::clog << '\n';
    }
    {
        // Using simple algorithms, transform (provided by the original thread author
        std::vector<int> out;
        const auto add([&out](const auto &p){ out.push_back(p.first); return p.second; });
        static_cast<void>(std::transform(std::begin(number_pair),
                            std::end(number_pair),
                            std::back_inserter(out), add));
        std::clog << "simple algo\n\t";
        for(const auto e : out) {
            std::clog << e << ' ';
        }
        std::clog << '\n';
    }

    {
        const std::vector<std::vector<int>> number_pair = { {1, 4}, {2, 3}, {3, 9} };
        const auto numbers = number_pair | ranges::views::all | ranges::actions::join;
        std::clog << "vec of vec\n\t";
        for (const auto number : numbers)
        {
            std::clog << number << ' ';
        }
        std::clog << '\n';
    }

    {
        const std::vector<std::pair<int, int>> number_pair = { {1, 4}, {2, 3}, {3, 9} };
        const auto numbers = ranges::views::concat(number_pair | ranges::views::keys, number_pair | ranges::views::values);
        std::clog << "concat of zip (keys,vals)\n\t";
        for (const auto number : numbers)
        {
            std::clog << number << ' ';
        }
        std::clog << '\n';
    }

    {
        const std::vector<std::pair<int, int>> number_pair = { {1, 4}, {2, 3}, {3, 9} };
        const auto numbers = number_pair | ranges::views::transform([](const auto& p) { return std::vector<int> {p.first, p.second}; }) | ranges::actions::join;
        std::clog << "transform + join\n\t";
        for (const auto number : numbers)
        {
            std::clog << number << ' ';
        }
        std::clog << '\n';
    }
}
