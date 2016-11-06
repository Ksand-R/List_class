#include "_List.h"
#include <gtest.h>

TEST(TList, can_add_node_in_empty_list)
{
	_List<char> l;
	ASSERT_NO_THROW(l.add_el_in_head('a'));
}

TEST(Tlist, cant_del_from_empty_list)
{
	_List<char> l;

	EXPECT_ANY_THROW(l.del_el_fr_head());
	EXPECT_ANY_THROW(l.del_el_fr_tail());
	//EXPECT_ANY_THROW(l.del_node()
}

TEST(Tlist, cant_find_ptr_in_empty_list)
{
	_List<char> l;
	ASSERT_ANY_THROW(l.find_ptr('b'));
}

TEST(Tlist, can_find_ptr)
{
	_List<char> l;
	l.add_el_in_tail('a');
	ASSERT_NO_THROW(l.find_ptr('a'));

}

TEST(Tlist, cant_find_ptr)
{
	_List<char> l;
	l.add_el_in_tail('a');
	ASSERT_ANY_THROW(l.find_ptr('b'));

}

TEST(Tlist, list_is_correctly_empty)
{
	_List<char> l;
	l.add_el_in_tail('a');
	l.del_el_fr_tail();
	EXPECT_EQ(l.GetSize(), 0);

}

TEST(TList, can_add_node_in_tail)
{
	_List<char> l;
	l.add_el_in_tail('a');
	EXPECT_EQ('a', l.viewData(l.find_ptr('a')));
}
TEST(Tlist, can_del_node_from_tail)
{
	_List<char> l;
	l.add_el_in_tail('a'); 
	l.add_el_in_tail('b');
	l.del_el_fr_tail();
	EXPECT_EQ('a', l.viewData(l.find_ptr('a')));
}

TEST(TList, can_add_node_in_head)
{
	_List<char> l;
	l.add_el_in_head('a');
	EXPECT_EQ('a', l.viewData(l.find_ptr('a')));
}

TEST(Tlist, can_del_node_from_head)
{
	_List<char> l;
	l.add_el_in_head('a');
	l.add_el_in_head('b');
	l.del_el_fr_head();
	EXPECT_EQ('a', l.viewData(l.find_ptr('a')));
}

TEST(Tlist, can_add_node_after_ptr)
{
	_List<char> l;
	l.add_el_in_head('a');
	_Node<char>* ptr = l.find_ptr('a');
	l.add_node(ptr, 'b');
	EXPECT_EQ('b', l.viewData(l.find_ptr('b')));

}
