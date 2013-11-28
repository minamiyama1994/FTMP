# Template Meta Programming Library -- TMP Lib --

## Motivation

There is a boost::mpl to those famous as a library of Template Meta Programming.

But boost::mpl has been designed in compliance with the design of the STL.

**This is a problem.**

Template Meta Programming is a functional programming, manners of STL in accordance with the method of procedural is not amenable.

If you make the Template Meta Programming, the design not including the STL, it should be followed in library design of functional languages ​​such as Haskell.

Libraries created such, according to the procedure of the functional is the library.

## Notice

Entire library is stored in the "tmp" namespace

## Reference

### Data Structure

#### list

Equivalent to Data.List.List of Haskell.

***

#### set

Equivalent to Data.Set.Set of Haskell.

***

#### dict

Equivalent to Data.Map.Map of Haskell.

***

### Utility

#### eval

##### interface

template < typename T >
struct eval ;

##### argument

###### T

Class types F <T_...>.

##### return

typename F <typename T_::type...>::type.

***

#### eval_if

##### interface

template < typename tf , typename T1 , typename T2 >
struct eval_if ;

##### argument

###### tf

Boolean value.

###### T1

Some type.

###### T2

Some type.

##### return

T1 tf is if true, T2 tf is false.

***

#### eval\_if_c

##### interface

template < bool tf , typename T1 , typename T2 >
truct eval\_if_c ;

##### argument

###### tf

Boolean value.

###### T1

Some type.

###### T2

Some type.

##### return

T1 tf is if true, T2 tf is false.

***

#### if_

##### interface

template < typename tf , typename T1 , typename T2 >
struct if_ ;

##### argument

###### tf

Boolean value.

###### T1

Some type.

###### T2

Some type.

##### return

T1 tf is if true, T2 tf is false.

***

#### if_c

##### interface

template < bool tf , typename T1 , typename T2 >
struct if_c ;

##### argument

###### tf

Boolean value.

###### T1

Some type.

###### T2

Some type.

##### return

T1 tf is if true, T2 tf is false.

***

#### lambda

##### interface

template < typename func >
struct lambda ;

##### argument

###### func

Function.

##### return

new Functions of applying the arg... in the meta-function F in lambda <F>::apply<arg...>.

***

#### print

##### interface

template < typename T >
	struct print ;

##### argument

###### T

Type you want to see the details.

##### return

Type of argument.

However, this generates a compile error after that output type.

### Functions

#### all

Equivalent to Data.List.all of Haskell.

***

#### and_

Equivalent to (&&) of Haskell.

***

#### any

Equivalent to Data.List.any of Haskell.

***

#### append

Equivalent to Data.List.++ of Haskell.

***

#### at

Equivalent to Data.List.!! of Haskell.

***

#### complement

Equivalent to Data.Set.difference of Haskell.

***

#### composite

Equivalent to (.) of Haskell.

***

#### concat

Equivalent to Data.List.concat of Haskell.

***

#### cons

Equivalent to (:) of Haskell.

***

#### delete_

Equivalent to Data.Set.delete of Haskell.

***

#### elem

Equivalent to Data.List.elem of Haskell.

Equivalent to Data.Set.member of Haskell.

***

#### empty

Equivalent to Data.List.empty of Haskell.

Equivalent to Data.Set.empty of Haskell.

***

#### equal

Equivalent to (==) of Haskell.

***

#### filter

Equivalent to Data.List.filter of Haskell.

Equivalent to Data.Set.filter of Haskell.

***

#### find

Equivalent to Data.Set.findIndex of Haskell.

***

#### foldl

Equivalent to Data.List.foldl of Haskell.

***

#### foldr

Equivalent to Data.List.foldr of Haskell.

***

#### head

Equivalent to Data.List.head of Haskell.

***

#### id

Equivalent to id of Haskell.

***

#### init

Equivalent to Data.List.init of Haskell.

***

#### insert

Equivalent to Data.Set.insert of Haskell.

Equivalent to Data.Map.insert of Haskell.

***

#### integral

##### Summary

Type of integer.

***

#### intersection

Equivalent to Data.Set.intersection of Haskell.

***

#### last

Equivalent to Data.List.last of Haskell.

***

#### lookup

Equivalent to Data.Map.lookup of Haskell.

***

#### map

Equivalent to Data.List.map of Haskell.

Equivalent to Data.Set.map of Haskell.

***

#### nand

Equivalent to (\x y->not$x&&y) of Haskell.

***

#### not

Equivalent to not of Haskell.

***

#### or

Equivalent to (||) of Haskell.

***

#### size

Equivalent to Data.List.length of Haskell.

Equivalent to Data.Set.size of Haskell.

***

#### symmetric_difference

Equivalent to (\x y->union(difference x y)(difference y x)) of Haskell.

***

#### tail

Equivalent to Data.List.tail of Haskell.

***

#### to_dict

Convert to dict from a list or set.

***

#### to_list

Convert to list from a set or dict.

***

#### to_set

Convert to set from a list or dict.

***

#### typed_map

map made ​​to correspond to a value type from the type.

***

#### union_

Equivalent to Data.Set.union of Haskell.

***

#### unique

Equivalent to Data.List.nub of Haskell.

***

#### xor

Equivalent to (\x y->not(x&&y)&&(x||y)) of Haskell.

***

#### zip

Equivalent to Data.List.zip of Haskell.

Equivalent to Data.List.zip3 of Haskell.

Equivalent to Data.List.zip4 of Haskell.

Equivalent to Data.List.zip5 of Haskell.

Equivalent to Data.List.zip6 of Haskell.

Equivalent to Data.List.zip7 of Haskell.
