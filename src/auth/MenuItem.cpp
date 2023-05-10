#include "MenuItem.h"

#include <cassert>

using namespace std;

std::string MenuItem::Call(const vector<std::any>& args) const {
    // TODO check args lenth in debug builds

    assert(args.size() == m_args.size());

    return m_func(args);
}
