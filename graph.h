#pragma once

/// file: graph.h
/// Copyright (c) Apr 2017 Fengshan Liu(UESTC)

#include <unordered_map>
#include <memory>
#include <utility>

enum class enum_color :int { WHITE, GRAY, BLACK };
struct vertex
{
	int id;
	enum_color color;
	int pre;
	int dist;
};

class graph
{
public:
	graph();

	std::unordered_map<int, std::shared_ptr<vertex>> unord_map_id_pvtx;
	std::unordered_map<int, std::unordered_map<int, int>> unord_map_id_neibor;
};

