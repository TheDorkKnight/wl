GTEST_INC_DIR=../../googletest-release-1.11.0/googletest/include
GTEST_LIB_DIR=../../googletest-release-1.11.0/build/lib

CC=clang++
CXXFLAGS=-std=c++20 -I../include -isystem$(GTEST_INC_DIR)
LDFLAGS=-L$(GTEST_LIB_DIR) -lgtest
DEPS=../include/wl/block_iterator.h ../include/wl/default_map.h ../include/wl/discovery_locations.h ../include/wl/find_j_moves.h ../include/wl/game_state.h ../include/wl/i_nodes.h ../include/wl/investigator_abilities.h ../include/wl/investigator_id.h ../include/wl/j_moves.h ../include/wl/j_node_block_iterator.h ../include/wl/j_node_blocks_iterator.h ../include/wl/j_nodes.h ../include/wl/jack_inventory.h ../include/wl/node_blocks_iterator.h ../include/wl/player_locations.h ../include/wl/tagged_id.h ../include/wl/wl.h
ODIR=obj
OBJ = block_iterator_test.o find_j_moves_test.o i_node_test.o investigator_abilities_test.o jack_inventory_test.o jack_move_test.o map_node_test.o no_evidence_node_test.o node_blocks_iterator_test.o normal_node_test.o player_locations_test.o water_node_test.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CXXFLAGS)

wl_test: $(OBJ) main.cpp
	$(CC) -o $@ $^ $(CXXFLAGS) $(LDFLAGS)

test: wl_test
	./wl_test

.PHONY: clean test

clean:
	rm -f *.o wl_test
