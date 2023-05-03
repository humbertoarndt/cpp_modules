# Iheritance

Inheritance is tha capability of a class to derive properties and characteristics from another class. Inheritance is one of the most important features of OOP.

The purpose of using inheritance is to avoid duplicate code, since a **derived class** has access to the attributes and functionality of its **base class**.

the example bellow shows two classes with a similar code.

```c++
class Entity
{
	public:
		float	x, y;

		void	move(xa, ya)
		{
			x = xa;
			y = ya;
		}
};

class Player
{
	public:
		const char	*name
		float		x, y;

		void	move(xa, ya)
		{
			x = xa;
			y = ya;
		}

		void	printName(void)
		{
			std::cout << name << std::endl;
		}
};
```  

Using inheritance the block can be written as follows.

```c++
class Entity
{
	public:
		float	x, y;

		void	move(xa, ya)
		{
			x = xa;
			y = ya;
		}
};

class Player : public Entity
{
	public:
		const char	*name

		void	printName(void)
		{
			std::cout << name << std::endl;
		}
};
```  

In this case an object from the class `Player` will have the attributes `x` and `y`, as have access to `move()`, while having its own functionalities with `name` and `printName()`.  

## References
[Inheritance in C++ - The Cherno](https://www.youtube.com/watch?v=X8nYM8wdNRE)  
[Inheritance in C++ - Geeks for Geeks](https://www.geeksforgeeks.org/inheritance-in-c/)  

# Private x Protected

**Private** members are only accessible within the class definig them.

**Protected** members are accessible in the class that defines them, and in classes that inherit from that class.

**Public** members are accessible for all and everyone.

## References
[What is the difference between private and protected members of C++ classes?](https://stackoverflow.com/questions/224966/what-is-the-difference-between-private-and-protected-members-of-c-classes)  