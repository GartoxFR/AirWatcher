#include "MenuItem.h"

#include <cassert>

using namespace std;

unique_ptr<Printable> MenuItem::Call(const vector<void*>& args) const {
    assert(args.size() == m_args.size());

    return m_func(args);
}
