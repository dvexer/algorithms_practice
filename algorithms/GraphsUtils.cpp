#include "GraphsUtils.hpp"
#include <utility>
#include <limits>
#include <queue>
#include <map>


typedef std::pair<uint32_t, uint32_t> pair_uint;
constexpr uint32_t inf = std::numeric_limits<uint32_t>::max();

namespace {

template<std::uint32_t N>
std::optional<uint32_t> min_dist_index(const std::array<uint32_t, N>& dist, const std::array<bool, N>& visited) {
    uint32_t min = inf;
    std::optional<uint32_t> min_index;
    for (uint32_t i = 0; i < N; ++i) {
        if (!visited[i] && min > dist[i]) {
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}

}

std::optional<uint32_t> dijkstra(const std::vector<std::vector<uint32_t>>& m, uint32_t s, uint32_t t) {
    if (m.empty())
        return std::nullopt;

    std::map<uint32_t, std::vector<pair_uint>> graph;
    std::map<uint32_t, bool> visited;
    std::map<uint32_t, uint32_t> dist;
    for (const auto& i : m) {
        graph[i[0]].emplace_back(i[1], i[2]);
        visited[i[0]] = false;
        visited[i[1]] = false;
        dist[i[0]] = inf;
        dist[i[1]] = inf;
    }

    std::priority_queue<pair_uint, std::vector<pair_uint>, std::greater<>> pq;

    pq.emplace(s, 0);

    while (!pq.empty()) {
        auto cur = pq.top();
        pq.pop();
        uint32_t cur_node = cur.first;
        if (visited[cur_node])
            continue;
        visited[cur_node] = true;

        for (const auto& to : graph[cur_node]) {
            uint32_t to_node = to.first;
            uint32_t to_dist = to.second + cur.second;

            if (!visited[to_node] && dist[to_node] > to_dist) {
                dist[to_node] = to_dist;
                pq.emplace(to_node, to_dist);
            }
        }
    }
    return (dist.count(t) != 0 && dist[t] != inf)
        ? std::make_optional<>(dist[t])
        : std::nullopt;
}

template<std::uint32_t N>
std::optional<uint32_t> dijkstra(const std::array<std::array<uint32_t, N>, N>& m, uint32_t s, uint32_t t) {
    if (s >= N || t >= N)
        return std::nullopt;

    std::array<uint32_t, N> dist;
    dist.fill(inf);
    std::array<bool, N> visited;
    visited.fill(false);

    dist[s] = 0;
    for (int i = 0; i < N; ++i) {
        const std::optional<uint32_t> mi = min_dist_index<N>(dist, visited);  // min index

        if (!mi.has_value()) // unlinked node
            continue;
        visited[*mi] = true;

        for (int j = 0; j < N; ++j) {
            if (!visited[j] && m[*mi][j] != 0 && dist[j] > m[*mi][j] + dist[*mi])
                dist[j] = m[*mi][j] + dist[*mi];
        }
    }

    return dist[t] != inf
           ? std::make_optional<>(dist[t])
           : std::nullopt;
}
