# Template Meta Programming Language Library -- TMP Lib --

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

### all

#### interface

template < typename func , typename seq >
struct all ;

##### argument

###### func

Meta-function that returns a boolean value for the element.

###### seq

set or list.

##### return

Boolean value representing func is whether to return true for all values of container.

***

### and_

#### interface

template < typename T1 , typename T2 >
struct and_ ;

##### argument

###### T1

boolean value.

###### T2

boolean value.

##### return

T1 && T2.

***

### any

#### interface

template < typename func , typename seq >
struct any ;

##### argument

###### func

Meta-function that returns a boolean value for the element.

###### seq

set or list.

##### return

Boolean value representing func is whether to return true for any value of container.

***

### append

#### interface

template < typename L1 , typename L2 >
struct append ;

##### argument

###### L1

list.

###### L2

list.

##### return

Combine the two lists.

***

### at

#### interface

template < typename L , typename index_type >
struct at ;

##### argument

###### L

list.

###### index_type

integral meta value.

##### return

Element of index_type th L.

***

### at

#### interface

template < typename L , typename index_type >
struct at ;

##### argument

###### L

list.

###### index_type

integral meta value.

##### return

Element of index_type th L.

***

### complement

#### interface

template < typename T1 , typename T2 >
struct complement ;

##### argument

###### T1

set.

###### T2

set.

##### return

A new set of extracted values are not included in the set T2 from the set T1.

***

### composite

#### interface

template < typename func , typename ... funcs >
struct composite ;

##### argument

###### func,funcs...

Functions who want to synthetic.

##### return

New function obtained by combining the Functions of the argument.

***

### concat

#### interface

template < typename seq >
struct concat ;

##### argument

###### seq

List of lists

##### return

Result of combining all of the list in the list.

***

### cons

#### interface

template < typename head , typename tail >
struct cons ;

##### argument

###### head

Element you want to add to the top of the list.

###### tail

The original list.

##### return

List with the addition of a new element to the front of the original list.

***

### delete_

#### interface

template < typename k , typename map >
struct delete_ ;

##### argument

###### k

Key you want to delete.

###### map

Dict the original.

##### return

Dict you have deleted the Key you want to delete from the original dict.

***

### dict

#### Summary

Dict data structure.

***

### elem

#### interface

template < typename T , typename seq >
struct elem ;

##### argument

###### T

Value you want to check to see if it is included in the container.

###### seq

Set or list, examine.

##### return

Boolean value indicating whether the value is included in the container.

***

### empty

#### interface

template < typename T >
struct empty ;

##### argument

###### T

Dict or set, or list, you want to check for empty.

##### return

boolean value that represents dict or set, or list, whether empty.

***

### equal

#### interface

template < typename T1 , typename T2 >
struct equal ;

##### argument

###### T1

Type you want to compare.

###### T2

Type you want to compare.

##### return

Boolean value representing *logically* two types of equality(behavior is different and so on std::is_same.).

***

### eval

#### interface

template < typename T >
struct eval ;

##### argument

###### T

Class types F <T_...>.

##### return

typename F <typename T_::type...>::type.

***

### eval_if

#### interface

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

### eval\_if_c

#### interface

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

### filter

#### interface

template < typename func , typename seq >
struct filter ;

##### argument

###### func

Meta-function that returns a boolean value takes one argument.

###### seq

set or list.

##### return

A new container to which you extracted the only value func returns true from the original container.

***

### find

#### interface

template < typename k , typename map >
struct find ;

##### argument

###### k

Type you want to check whether the key is included in the dict surveyed.

###### map

Dict surveyed.

##### return

Boolean value that represents the person of interest is to see whether it contains a dict surveyed.

***

### foldl

#### interface

template < typename func , typename a , typename bs >
struct foldl ;

##### argument

###### func

Meta-functions that accept two arguments.

###### a

The default value for bs is empty.

###### bs

List of convolution target.

##### return

result of the convolution left using the func bs.

***

### foldr

#### interface

template < typename func , typename b , typename as >
struct foldr ;

##### argument

###### func

Meta-functions that accept two arguments.

###### b

The default value for as is empty.

###### as

List of convolution target.

##### return

result of the convolution right using the func bs.

***

### head

#### interface

template < typename T >
struct head ;

##### argument

###### T

List to be retrieved the first value.

##### return

The value of the first of the original list.

***

### id

#### interface

template < typename T >
struct id ;

##### argument

###### T

Value you want to return as the return value.

##### return

Argument.

***

### id

#### interface

template < typename T >
struct id ;

##### argument

###### T

Value you want to return as the return value.

##### return

Argument.

***

### if_

#### interface

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

### if_c

#### interface

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

### init

#### interface

template < typename T >
struct init ;

##### argument

###### T

List value.

##### return

A new list obtained by removing the last value from the original list.

***

### insert

#### interface

template < typename T , typename set >
struct insert ;

##### argument

###### T

value you want to insert into the set.

###### set

Set into which it is inserted.

##### return

New set you have inserted the value set to the original.

***

### insert_dict

#### interface

template < typename k , typename a , typename dict_ >
struct insert_dict ;

##### argument

###### k

key of the value to be inserted into a dict.

###### a

value you want to insert into the dict.

###### dict_

Dict into which it is inserted.

##### return

New dict you have inserted the value dict to the original.

***

### integral

#### Summary

Type of integer.

***

### intersection

#### interface

template < typename T1 , typename T2 >
struct intersection ;

##### argument

###### T1

Set.

###### T2

Set.

##### return

New set obtained by extracting the intersection of the set T1 and T2 set.

***

### lambda

#### interface

template < typename func >
struct lambda ;

##### argument

###### func

Function.

##### return

new Functions of applying the arg... in the meta-function F in lambda <F>::apply<arg...>.

***

### last

#### interface

template < typename T >
struct last ;

##### argument

###### T

List.

##### return

value of the end of the list.

***

### last

#### interface

template < typename T >
struct last ;

##### argument

###### T

List.

##### return

value of the end of the list.

***

### list

#### Summary

List data structure.

***

### last

#### interface

template < typename T >
struct last ;

##### argument

###### T

List.

##### return

value of the end of the list.