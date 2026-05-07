// Exercise 1: Demonstrating public, protected, and private inheritance

#include <iostream>

class Base
{
	private:
		int privateInt;
		
	protected:
		int protectedInt;
		
	public:
		int publicInt;
		
		int getPrivateInt()
		{
			return privateInt;
		}
		
		int getProtectedInt()
		{
			return protectedInt;
		}
		
		int getPublicInt()
		{
			return publicInt;
		}
		
		void setPrivateInt(int val)
		{
			privateInt = val;
		}
		
		void setProtectedInt(int val)
		{
			protectedInt = val;
		}
		
		void setPublicInt(int val)
		{
			publicInt = val;
		}
};

class publicChild : public Base
{
	public:
		void displayAccess()
		{
			std::cout << "\n--- Public Inheritance ---";
			
			std::cout << "\nPrivate Int (via getter): " << getPrivateInt();
			
			std::cout << "\nProtected Int (direct access): " << protectedInt;

			std::cout << "\nPublic Int (direct access): " << publicInt;
		}
};

class protectedChild : protected Base
{
	public:
		void displayAccess()
		{
			std::cout << "\n\n--- Protected Inheritance ---";

			std::cout << "\nPrivate Int (via getter): " << getPrivateInt();

			std::cout << "\nProtected Int (direct access): " << protectedInt;

			std::cout << "\nPublic Int (direct access): " << publicInt;
		}
		
		void setValues(int priv, int prot, int pub)
		{
			setPrivateInt(priv);
			setProtectedInt(prot);
			setPublicInt(pub);
		}
};

class privateChild : private Base
{
	public:
		void displayAccess()
		{
			std::cout << "\n\n--- Private Inheritance ---";
					
			std::cout << "\nPrivate Int (via getter): " << getPrivateInt();

			std::cout << "\nProtected Int (direct access): " << protectedInt;

			std::cout << "\nPublic Int (direct access): " << publicInt;
		}
		
		void setValues(int priv, int prot, int pub)
		{
			setPrivateInt(priv);
			setProtectedInt(prot);
			setPublicInt(pub);
		}
};

int main()
{
	publicChild obj1;
	obj1.setPrivateInt(10);
	obj1.setProtectedInt(20);
	obj1.setPublicInt(30);
	obj1.displayAccess();
	

	protectedChild obj2;
	obj2.setValues(40, 50, 60);
	obj2.displayAccess();
	
	privateChild obj3;
	obj3.setValues(70, 80, 90); 
	obj3.displayAccess();
	
	std::cout << "\n\nSummary:";
	std::cout << "\n- Public Inheritance: Public and Protected members accessible, Private needs getter";
	std::cout << "\n- Protected Inheritance: All base members become protected in child";
	std::cout << "\n- Private Inheritance: All base members become private in child\n";
	
	return 0;
}
