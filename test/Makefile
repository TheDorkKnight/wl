GTEST_INC_DIR=../../googletest-release-1.11.0/googletest/include
GTEST_LIB_DIR=../../googletest-release-1.11.0/build/lib

CC=clang++
CXXFLAGS=-std=c++20 -I../include -isystem$(GTEST_INC_DIR)
LDFLAGS=-L$(GTEST_LIB_DIR) -lgtest
DEPS=block_iterator.h default_map.h discovery_locations.h find_j_moves.h game_state.h i_nodes.h investigator_abilities.h investigator_id.h j_moves.h j_node_block_iterator.h j_node_blocks_iterator.h j_nodes.h jack_inventory.h node_blocks_iterator.h player_locations.h tagged_id.h wl.h
ODIR=obj
OBJ = block_iterator_test.o find_j_moves_test.o i_node_test.o investigator_abilities_test.o jack_inventory_test.o jack_move_test.o map_node_test.o no_evidence_node_test.o node_blocks_iterator_test.o normal_node_test.o player_locations_test.o water_node_test.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CXXFLAGS)

wl_test: $(OBJ) main.cpp
	$(CC) -o $@ $^ $(CXXFLAGS) $(LDFLAGS)

test: wl_test
	./wl_test

.PHONY: clean

clean:
	rm -f *.o wl_test
