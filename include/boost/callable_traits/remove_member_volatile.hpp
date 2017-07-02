/*

@copyright Barrett Adair 2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

*/

#ifndef BOOST_CLBL_TRTS_REMOVE_MEMBER_VOLATILE_HPP
#define BOOST_CLBL_TRTS_REMOVE_MEMBER_VOLATILE_HPP

#include <boost/callable_traits/detail/core.hpp>

namespace boost { namespace callable_traits {

//[ remove_member_volatile_hpp
/*`
[section:ref_remove_member_volatile remove_member_volatile]
[heading Header]
``#include <boost/callable_traits/remove_member_volatile.hpp>``
[heading Definition]
*/

template<typename T>
using remove_member_volatile_t = //see below
//<-
    detail::try_but_fail_if_invalid<
        typename detail::traits<T>::remove_member_volatile,
        member_qualifiers_are_illegal_for_this_type>;
//->

template<typename T, typename U = remove_member_volatile_t<T>>
struct remove_member_volatile {
    using type = U;
};
//<-
}} // namespace boost::callable_traits
//->

/*`
[heading Constraints]
* `T` must be a function type or a member function pointer type

[heading Behavior]
* A substitution failure occurs if the constraints are violated.
* Removes the member `volatile` qualifier from `T`, if present.

[heading Input/Output Examples]
[table
    [[`T`]                              [`remove_member_volatile_t<T>`]]
    [[`int() volatile`]                 [`int()`]]
    [[`int(foo::*)() volatile`]         [`int(foo::*)()`]]
    [[`int(foo::*)() volatile &`]       [`int(foo::*)() &`]]
    [[`int(foo::*)() volatile &&`]      [`int(foo::*)() &&`]]
    [[`int(foo::*)() volatile`]         [`int(foo::*)()`]]
    [[`int(foo::*)() const volatile`]   [`int(foo::*)() const`]]
    [[`int`]                            [(substitution failure)]]
    [[`int (&)()`]                      [(substitution failure)]]
    [[`int (*)()`]                      [(substitution failure)]]
    [[`int foo::*`]                     [(substitution failure)]]
    [[`int (foo::* const)()`]           [(substitution failure)]]
]

[heading Example Program]
[import ../example/remove_member_volatile.cpp]
[remove_member_volatile]
[endsect]
*/
//]

#endif // #ifndef BOOST_CLBL_TRTS_REMOVE_MEMBER_VOLATILE_HPP
