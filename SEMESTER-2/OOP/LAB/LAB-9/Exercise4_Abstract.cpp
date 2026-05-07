// Exercise 4: Encryption techniques using abstract class and pure virtual function

#include <iostream>
#include <string.h>

class EncryptionTechnique
{
	protected:
		char* message;
		char* encryptedMessage;
		
	public:
		// Constructor
		EncryptionTechnique()
		{
			message = NULL;
			encryptedMessage = NULL;
		}
		
		// Destructor
		virtual ~EncryptionTechnique()
		{
			if (message != NULL)
			{
				delete[] message;
			}
			if (encryptedMessage != NULL)
			{
				delete[] encryptedMessage;
			}
		}
		
		// Function to set message
		void setMessage(const char* msg)
		{
			if (message != NULL)
			{
				delete[] message;
			}
			message = new char[strlen(msg) + 1];
			strcpy(message, msg);
		}
		
		// Pure virtual function
		virtual void encrypt() = 0;
		
		// Display encrypted message
		virtual void displayEncrypted() = 0;
};

class EncryptionTechnique1 : public EncryptionTechnique
{
	public:
		// Implementation of encrypt function
		void encrypt()
		{
			if (message == NULL)
			{
				return;
			}
			
			// Calculate size needed for encrypted message
			int len = strlen(message);
			int encryptedSize = len * 3 + 1; // max 3 digits per character + null terminator
			
			if (encryptedMessage != NULL)
			{
				delete[] encryptedMessage;
			}
			encryptedMessage = new char[encryptedSize];
			encryptedMessage[0] = '\0';
			
			// Convert each character to ASCII code
			char temp[10];
			for (int i = 0; i < len; i++)
			{
				sprintf(temp, "%d", (int)message[i]);
				strcat(encryptedMessage, temp);
			}
		}
		
		// Display encrypted message
		void displayEncrypted()
		{
			std::cout << "\n--- Encryption Technique 1 ---";
			std::cout << "\nOriginal Message: " << message;
			std::cout << "\nEncryption Method: Convert alphabets to ASCII codes";
			std::cout << "\nEncrypted Message: " << encryptedMessage;
			std::cout << "\n";
		}
};

class EncryptionTechnique2 : public EncryptionTechnique
{
	public:
		// Implementation of encrypt function
		void encrypt()
		{
			if (message == NULL)
			{
				return;
			}
			
			// Calculate size needed for encrypted message
			int len = strlen(message);
			int encryptedSize = len * 3 + 1; // max 3 digits per character + null terminator
			
			if (encryptedMessage != NULL)
			{
				delete[] encryptedMessage;
			}
			encryptedMessage = new char[encryptedSize];
			encryptedMessage[0] = '\0';
			
			// Convert each character to ASCII code + 2
			char temp[10];
			for (int i = 0; i < len; i++)
			{
				sprintf(temp, "%d", (int)message[i] + 2);
				strcat(encryptedMessage, temp);
			}
		}
		
		// Display encrypted message
		void displayEncrypted()
		{
			std::cout << "\n--- Encryption Technique 2 ---";
			std::cout << "\nOriginal Message: " << message;
			std::cout << "\nEncryption Method: Convert alphabets to ASCII codes + 2";
			std::cout << "\nEncrypted Message: " << encryptedMessage;
			std::cout << "\n";
		}
};

int main()
{
	char inputMessage[100];
	
	std::cout << "=== Encryption System ===\n";
	std::cout << "\nEnter a message to encrypt: ";
	std::cin.getline(inputMessage, 100);
	
	// Creating encryption objects
	EncryptionTechnique1 technique1;
	EncryptionTechnique2 technique2;
	
	// Setting message for both techniques
	technique1.setMessage(inputMessage);
	technique2.setMessage(inputMessage);
	
	// Encrypting using both techniques
	technique1.encrypt();
	technique2.encrypt();
	
	// Displaying encrypted messages
	technique1.displayEncrypted();
	technique2.displayEncrypted();
	
	// Using polymorphism with base class pointer
	std::cout << "\n--- Using Polymorphism ---";
	EncryptionTechnique* encPtr;
	
	encPtr = &technique1;
	std::cout << "\nUsing Technique 1:";
	encPtr->displayEncrypted();
	
	encPtr = &technique2;
	std::cout << "\nUsing Technique 2:";
	encPtr->displayEncrypted();
	
	return 0;
}
