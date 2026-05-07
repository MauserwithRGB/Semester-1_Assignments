// Exercise 5: Decryption techniques using abstract class and pure virtual function

#include <iostream>
#include <string.h>
#include <stdlib.h>

class DecryptionTechnique
{
	protected:
		char* encryptedMessage;
		char* decryptedMessage;
		
	public:
		// Constructor
		DecryptionTechnique()
		{
			encryptedMessage = NULL;
			decryptedMessage = NULL;
		}
		
		// Destructor
		virtual ~DecryptionTechnique()
		{
			if (encryptedMessage != NULL)
			{
				delete[] encryptedMessage;
			}
			if (decryptedMessage != NULL)
			{
				delete[] decryptedMessage;
			}
		}
		
		// Function to set encrypted message
		void setEncryptedMessage(const char* msg)
		{
			if (encryptedMessage != NULL)
			{
				delete[] encryptedMessage;
			}
			encryptedMessage = new char[strlen(msg) + 1];
			strcpy(encryptedMessage, msg);
		}
		
		// Pure virtual function
		virtual void decrypt() = 0;
		
		// Display decrypted message
		virtual void displayDecrypted() = 0;
};

class DecryptionTechnique1 : public DecryptionTechnique
{
	public:
		// Implementation of decrypt function
		void decrypt()
		{
			if (encryptedMessage == NULL)
			{
				return;
			}
			
			int len = strlen(encryptedMessage);
			if (decryptedMessage != NULL)
			{
				delete[] decryptedMessage;
			}
			decryptedMessage = new char[len + 1];
			
			int decIndex = 0;
			int i = 0;
			
			// Parse encrypted message and convert back to characters
			while (i < len)
			{
				char numStr[4] = {0};
				int numIndex = 0;
				
				// Read 2-3 digits for ASCII code
				while (i < len && numIndex < 3)
				{
					numStr[numIndex] = encryptedMessage[i];
					numIndex++;
					i++;
					
					// Check if we have a valid ASCII code
					int asciiCode = atoi(numStr);
					if (asciiCode >= 32 && asciiCode <= 126)
					{
						// Valid printable ASCII character
						decryptedMessage[decIndex] = (char)asciiCode;
						decIndex++;
						break;
					}
				}
			}
			
			decryptedMessage[decIndex] = '\0';
		}
		
		// Display decrypted message
		void displayDecrypted()
		{
			std::cout << "\n--- Decryption Technique 1 ---";
			std::cout << "\nEncrypted Message: " << encryptedMessage;
			std::cout << "\nDecryption Method: Convert ASCII codes back to alphabets";
			std::cout << "\nDecrypted Message: " << decryptedMessage;
			std::cout << "\n";
		}
};

class DecryptionTechnique2 : public DecryptionTechnique
{
	public:
		// Implementation of decrypt function
		void decrypt()
		{
			if (encryptedMessage == NULL)
			{
				return;
			}
			
			int len = strlen(encryptedMessage);
			if (decryptedMessage != NULL)
			{
				delete[] decryptedMessage;
			}
			decryptedMessage = new char[len + 1];
			
			int decIndex = 0;
			int i = 0;
			
			// Parse encrypted message and convert back to characters
			while (i < len)
			{
				char numStr[4] = {0};
				int numIndex = 0;
				
				// Read 2-3 digits for ASCII code
				while (i < len && numIndex < 3)
				{
					numStr[numIndex] = encryptedMessage[i];
					numIndex++;
					i++;
					
					// Check if we have a valid ASCII code (subtract 2 first)
					int asciiCode = atoi(numStr) - 2;
					if (asciiCode >= 32 && asciiCode <= 126)
					{
						// Valid printable ASCII character
						decryptedMessage[decIndex] = (char)asciiCode;
						decIndex++;
						break;
					}
				}
			}
			
			decryptedMessage[decIndex] = '\0';
		}
		
		// Display decrypted message
		void displayDecrypted()
		{
			std::cout << "\n--- Decryption Technique 2 ---";
			std::cout << "\nEncrypted Message: " << encryptedMessage;
			std::cout << "\nDecryption Method: Convert ASCII codes - 2 back to alphabets";
			std::cout << "\nDecrypted Message: " << decryptedMessage;
			std::cout << "\n";
		}
};

int main()
{
	char encryptedMsg1[200];
	char encryptedMsg2[200];
	
	std::cout << "=== Decryption System ===\n";
	
	std::cout << "\nEnter encrypted message (Technique 1): ";
	std::cin.getline(encryptedMsg1, 200);
	
	std::cout << "Enter encrypted message (Technique 2): ";
	std::cin.getline(encryptedMsg2, 200);
	
	// Creating decryption objects
	DecryptionTechnique1 technique1;
	DecryptionTechnique2 technique2;
	
	// Setting encrypted messages
	technique1.setEncryptedMessage(encryptedMsg1);
	technique2.setEncryptedMessage(encryptedMsg2);
	
	// Decrypting using both techniques
	technique1.decrypt();
	technique2.decrypt();
	
	// Displaying decrypted messages
	technique1.displayDecrypted();
	technique2.displayDecrypted();
	
	// Using polymorphism with base class pointer
	std::cout << "\n--- Using Polymorphism ---";
	DecryptionTechnique* decPtr;
	
	decPtr = &technique1;
	std::cout << "\nUsing Technique 1:";
	decPtr->displayDecrypted();
	
	decPtr = &technique2;
	std::cout << "\nUsing Technique 2:";
	decPtr->displayDecrypted();
	
	std::cout << "\n\n--- Example ---";
	std::cout << "\nFor 'Hello'";
	std::cout << "\nEncrypted (Technique 1): 7269767679";
	std::cout << "\nEncrypted (Technique 2): 7471787881";
	std::cout << "\n";
	
	return 0;
}
