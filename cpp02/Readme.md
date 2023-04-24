# Othodox Canonical Class Form

In the C++98 the Othodox Canonical Class Form have four methods that the C++ compiler generates for us:  

| Method | Description |
|---|---|
| Default Constructor | Constructor is a function that has the same name as the Class with no return type, and its used to initialize an object |
| Copy Constructor | Copy Constructor is called when a new object is creted from an existing object, as a copy of the existing object |
| Destructor | Destructor is a function that destroys an object allocated in the memory |
| Copy Assignment Operator | Copy Assignment Operator is called when an already initialized object is assigned a new value from another existing object |  

Now on a standart class in C++ should look like the following code:

```c++
class Foo
{
	public:
		Foo(void);
		Foo(Foo const &src);
		~Foo(void);
		Foo & operator = (Foo const &rhs);
};
```  
And the methods implementatios as this:

```c++

// =============================================================================
// CONSTRUCTOR & DESTRUCTOR
// =============================================================================

Foo::Foo(void)
{
	return ;
}

Foo::Foo(Foo const &src)
{
	*this = src;
	return ;
}

Foo::~Foo(void)
{
	return ;
}

// =============================================================================
// OPERATOR
// =============================================================================

Foo & Foo::operator= (Foo const &rhs)
{
	if (this != &rhs)
		// Assign values
	return *this;
}
```  

## References

[Orthodox Canonical Class Form](https://www.francescmm.com/orthodox-canonical-class-form/)  
[Programming example: Class constructor](https://www.youtube.com/watch?v=voU1oNf6Y6k)  
[Programming example: Copy assignment operator](https://www.youtube.com/watch?v=6wVG4OJxvww)  
[Programming example: Class destructor](https://www.youtube.com/watch?v=qDouTB3_s7E)  
[Programming example: Class copy constructor](https://www.youtube.com/watch?v=rVyx6p3YDLY&t=303s)  
[Copy Constructor C++](https://www.youtube.com/watch?v=GoEn9UnC0eI)  
[Copy Assignment Operator Overloading C++](https://www.youtube.com/watch?v=SjU5Y-rY56o)  
