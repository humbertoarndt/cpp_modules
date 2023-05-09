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
And the methods implementation look like this:

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

# Operator Overloading

## What is an operator?

Operator is a symbol used to perform something, like math operators (+, -, *, /, %), logic operators (&&, ||, ==, !=, <, <=, >, >=), pointer and reference operators (**foo, &foo), or the bit shifthing operators (<<, >>), also new (new Foo()) and delete (delete []). [See more](https://en.cppreference.com/w/cpp/language/operators)

## What is Overloading Operator?

Overloading means to give give a new meaning, or adding new parameters. In this case it's used to define or change the behavior of an operator in the program. In C++ we can make operators work for user-defined classes, as an example, we can overload the operator '+' in a class like String so that we can concatenate two strings by just using '+'.

The example bellow will result in an error, since `Foo` is not a **Fundamental type** in C++.

```c++
class Foo
{
	public:
		int x;
};

int	main(void)
{
	Foo f1.x = 2;
	Foo f2.x = 2;

	std::cout << (f1 + f2) << std::endl;
	return (0);
}
```  

In order to make this sum works an overload of the **+** operator is needed, so we can define what is the behavior the program must follow when the sum is found.

```c++
class	Foo
{
	public:
		int x;

		/* Sum operator overload */
		int Foo::operator + (const Foo &rhs) const; 
};

int	Foo::operator + (const Foo &rhs)
{
	return((int)(this->x + rhs->x));
}

int	main(void)
{
	Foo f1.x = 2;
	Foo f2.x = 2;

	std::cout << (f1 + f2) << std::endl;
	return (0);
}
```  

## References

[OPERATORS and OPERATOR OVERLOADING in C++](https://www.youtube.com/watch?v=mS9755gF66w)  
[C++ : What is 0xFF and why is it shifted 24 times?](https://www.youtube.com/watch?v=MncgPn6Nm2I)  
[Operator Overloading in C++](https://www.geeksforgeeks.org/operator-overloading-cpp/)  
