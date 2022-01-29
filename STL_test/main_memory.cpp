#include "../STL/memory/memory.hpp"
#include <assert.h>
#include <iostream>
#include <memory>

static size_t cnt;

class Myint
{
public:
    
    Myint(int x): val(x)
    {
        cnt++;
    }

    Myint(const Myint &x) : val(x.val)
    {
        cnt++;
    }
    
    ~Myint()
    {
        cnt--;
    }

    int get_val() const
    {
        return val;
    }

private:

    int val;

};


typedef ft::allocator<float> Myal;

Myal get_al()
{
    return Myal();
}

/*
**
** Testing Allocator
**
*/

void test_alloc()
{
    float f1;
    Myal::size_type *p_size = (size_t)0;
    //Myal::difference_type *p_val = (ptrdiff_t *)0;
    Myal::pointer *p_ptr = (float **)0;
    Myal::const_pointer *p_cptr = (const float **)0; 
    Myal::reference  p_ref = f1; 
    Myal::const_reference p_cref = (const float &)f1;
    Myal::value_type *p_dist = (float *)0;
    //Myal::rebind<int>::poiner *pv_iptr = (int **)0;
    Myal al0 = get_al();
    Myal al(al0);
    
    //ft::allocator<void>::pointer *pv_ptr = (void **)0;

    float *pf1 = al0.address(f1);

    //pf1 = al.allocate(3, 0);
}


int main()
{
    test_alloc();
    std::cout << "Success testing <memory> \n";

    return (0);
}