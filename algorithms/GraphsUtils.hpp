#ifndef ALGORITHMS_PRACTICE_GRAPHSUTILS_HPP
#define ALGORITHMS_PRACTICE_GRAPHSUTILS_HPP

#include <array>
#include <vector>
#include <optional>
#include <cinttypes>

/**
 * @param m matrix representing graph in format [{start_node, target_node, distance}]
 * @param s source node
 * @param t target node
 * @return length of shortest path if exist
 */
std::optional<uint32_t> dijkstra(const std::vector<std::vector<uint32_t>>& m, uint32_t s, uint32_t t);

/**
 *
 * @tparam N size of square matrix
 * @param m adjacency matrix
 * @param s source node
 * @param t target node
 * @return length of shortest path if exist
 */
template<std::uint32_t N>
std::optional<uint32_t> dijkstra(const std::array<std::array<uint32_t, N>, N>& m, uint32_t s, uint32_t t);

#endif //ALGORITHMS_PRACTICE_GRAPHSUTILS_HPP
