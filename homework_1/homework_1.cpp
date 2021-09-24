#include "homework_1.h"

int main(int argc, char const *argv[])
{
	std::ifstream file("PhoneBook.txt");
	
	if(!file.is_open())
	{
		std::cout << "Файл не может быть открыт!!!" << std::endl;
		return 1;
	}
	
	PhoneBook book(file);
	std::cout << "Original" << std::endl;
	std::cout << book;

	std::cout << "Sort ByPhone" << std::endl;
	book.SortByPhone();
	std::cout << book;

	std::cout << "Sort ByName" << std::endl;
	book.SortByName();
	std::cout << book;

	std::cout << "Change Phone Number" << std::endl;
	book.ChangePhoneNumber({"Gerasimov", "Miroslav", "Stanislavovich"}, {7, 495, "322223", 1256});
	std::cout << book;
	
	std::cout << "Get Phone Number" << std::endl;
	std::string pers = "Gerasimov";
	std::cout << pers << ": " << book.GetPhoneNumber(pers) << std::endl;
	pers = "Kukuev";
	std::cout << pers << ": " << book.GetPhoneNumber(pers) << std::endl;
	pers = "Solovev";
	std::cout << pers << ": " << book.GetPhoneNumber(pers) << std::endl;

	std::cout << "end";


	return 0;
}