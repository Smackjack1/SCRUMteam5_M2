#ifndef __GUI__
#define __GUI__
#include"Facade.h"
#include<fstream>
#include<string>
//#include <msclr\marshal_cppstd.h>
/*
<Form1 > Form1.h
Used for the Graphical User Interface.
Precondition: The form is compiledand blank ready for user commands.Help button will display the read me file for assistance.
Postcondition : The memory content display is showing the current content of the memory arrayand the commands are shown on the left side.
Functions :
	Button1 : Help button, displays read me file for user assistance
	TextField : Used for taking command from the user to put into memory.
	Memory_content : Displays the content in main memory.
*/
bool executing = false;
using Itype = String ^;
bool timeForUserInput = false;
using System::Runtime::InteropServices::Marshal;
Facade programAccess = Facade();
String^ convertToSystemString(std::string toConvert)
{
	String^ convertedSystemString = gcnew String(toConvert.c_str());
	return convertedSystemString;
}
std::string convertFromSystemString(String^ string)
{
	System::IntPtr pointer = Marshal::StringToHGlobalAnsi(string);
	char* charPointer = reinterpret_cast<char*>(pointer.ToPointer());
	std::string returnString(charPointer, string->Length);
	Marshal::FreeHGlobal(pointer);

	return returnString;
}
namespace CppCLRWinformsProjekt {
	
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	

	/// <summary>
	/// Zusammenfassung für Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Konstruktorcode hier hinzufügen.
			//
		}

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textField;
	protected:


	private: System::Windows::Forms::PageSetupDialog^ pageSetupDialog1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ executeButton;
	private: System::Windows::Forms::Button^ loadButton;
	private: System::Windows::Forms::Button^ saveButton;


	private: System::Windows::Forms::Label^ memory_content;
	private: System::Windows::Forms::Label^ program;
	private: System::Windows::Forms::TextBox^ textBox1;


	protected:

	private:
		/// <summary>
		/// Erforderliche Designervariable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode für die Designerunterstützung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
		/// </summary>
		void InitializeComponent(void)
		{
			this->executeButton = (gcnew System::Windows::Forms::Button());
			this->loadButton = (gcnew System::Windows::Forms::Button());
			this->saveButton = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textField = (gcnew System::Windows::Forms::TextBox());
			this->pageSetupDialog1 = (gcnew System::Windows::Forms::PageSetupDialog());
			this->memory_content = (gcnew System::Windows::Forms::Label());
			this->program = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// textField
			// 
			this->textField->Location = System::Drawing::Point(12, 45);
			this->textField->Multiline = true;
			this->textField->Name = L"textField";
			this->textField->Size = System::Drawing::Size(174, 316);
			this->textField->TabIndex = 1;
			this->textField->TextChanged += gcnew System::EventHandler(this, &Form1::textField_TextChanged);
			this->textField->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::textField_KeyDown);
			this->textField->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::textField_KeyPress);
			this->textField->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::textField_KeyUp);
			//
			//Execute Button
			//
			this->executeButton->Location = System::Drawing::Point(20, 388);
			this->executeButton->Name = L"executeButton";
			this->executeButton->Size = System::Drawing::Size(106, 37);
			this->executeButton->TabIndex = 2;
			this->executeButton->Text = L"Execute";
			this->executeButton->UseVisualStyleBackColor = true;
			this->executeButton->Click += gcnew System::EventHandler(this, &Form1::execute_Click);
			//
			//Load Button
			//
			this->loadButton->Location = System::Drawing::Point(200, 388);
			this->loadButton->Name = L"loadButton";
			this->loadButton->Size = System::Drawing::Size(106, 37);
			this->loadButton->TabIndex = 2;
			this->loadButton->Text = L"Load";
			this->loadButton->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::load_Click);
			//
			//Save Button
			//
			this->saveButton->Location = System::Drawing::Point(320, 388);
			this->saveButton->Name = L"saveButton";
			this->saveButton->Size = System::Drawing::Size(106, 37);
			this->saveButton->TabIndex = 2;
			this->saveButton->Text = L"Save";
			this->saveButton->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::save_Click);
			// 
			// Help Button
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(440, 388);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(106, 37);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Help";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// memory_content
			// 
			this->memory_content->AutoSize = true;
			this->memory_content->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->memory_content->Location = System::Drawing::Point(204, 15);
			this->memory_content->Name = L"memory_content";
			this->memory_content->Size = System::Drawing::Size(126, 20);
			this->memory_content->TabIndex = 6;
			this->memory_content->Text = L"Memory Content";
			this->memory_content->Click += gcnew System::EventHandler(this, &Form1::memory_content_Click);
			// 
			// program
			// 
			this->program->AutoSize = true;
			this->program->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->program->Location = System::Drawing::Point(12, 15);
			this->program->Name = L"program";
			this->program->Size = System::Drawing::Size(69, 20);
			this->program->TabIndex = 7;
			this->program->Text = L"Program";
			// 
			// textBox1
			// 
			this->textBox1->ReadOnly = true;
			//this->textBox1->Enabled = false;
			this->textBox1->Location = System::Drawing::Point(207, 45);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(533, 316);
			this->textBox1->TabIndex = 8;
			this->textBox1->Text = convertToSystemString(programAccess.getMemory());
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(782, 437);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->program);
			this->Controls->Add(this->memory_content);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textField);
			this->Controls->Add(this->executeButton);
			this->Controls->Add(this->loadButton);
			this->Controls->Add(this->saveButton);
			this->Name = L"Form1";
			this->Text = L"UVSIM";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		bool nonNumberEntered = false;
		bool bRun = false;
		//int lineNum = 0;
	private: System::Void Form1_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textField_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		//MessageBox::Show("hello");
	}
	private: System::Void textField_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {



	}
	private: System::Void textField_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		// Determine whether the keystroke is a number from the top of the keyboard.
	// Initialize the flag to false.
		nonNumberEntered = false;



		// Determine whether the keystroke is a number from the top of the keyboard.
		if (e->KeyCode < Keys::D0 || e->KeyCode > Keys::D9)
		{
			// Determine whether the keystroke is a number from the keypad.
			if (e->KeyCode < Keys::NumPad0 || e->KeyCode > Keys::NumPad9)
			{
				// Determine whether the keystroke is a backspace.
				if (e->KeyCode != Keys::Back)
				{
					if (e->KeyCode == Keys::Enter)
					{
						try
						{
							String^ firstline;
							nonNumberEntered = false;
							cli::array<Itype>^ myLines = textField->Lines;
							if (myLines->Length == 0)
							{
								firstline = "";
							}
							else
							{
								firstline = myLines[myLines->Length - 1];
							}
							
							//myLines[lineNum] = "Enter Command: ";
							if (timeForUserInput == true) // we go here only when execution has begun
							{
								//print that we're halting
								if (programAccess.getCurrentOpCode() == "10")
								{
									//take user input
									programAccess.opRead(convertFromSystemString(firstline));
									programAccess.incrementPC(1);
									timeForUserInput = false;
								}
								executeEverything();
							}
							this->textBox1->Text = convertToSystemString(programAccess.getMemory());
							//programAccess.addCommand("whatup");
							//lineNum++;
						}
						catch(runtime_error& e)
						{
							MessageBox::Show(convertToSystemString(e.what()));
							//need everything to stop
							exit(1);
						}
						



						/*
						int charIndex = textField->GetFirstCharIndexFromLine(lineNum);
						String^ opCode = textField->Text;
						String^ currLine = Convert::ToString(textField->Text[charIndex]);
						for (int i = charIndex; i <= textField->Lines->Length; i++) {
							String^ currLine = Convert::ToString(textField->Text[i]);
							MessageBox::Show(currLine);
							if (currLine = "\o") {
								break;
							}

						}
						*/

						
					}
				}
			}
		}

	}
	private: System::Void textField_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
	{
		if (nonNumberEntered == true)
		{
			// Stop the character from being entered into the control since it is non-numerical.
			e->Handled = true;
		}
	}

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e)
	{
		//Written by: Devan Hone

		String^ directory = Environment::CurrentDirectory;
		directory += "\\ReadMe.txt";
		System::Diagnostics::Process::Start(directory);

		//MessageBox::Show(directory, "Test Message");
	}
		   void executeEverything()
		   {
			   while (programAccess.getCurrentOpCode() != "43")
			   {
				   if (programAccess.getCurrentOpCode() == "10")
				   {

						this->textField->AppendText(Environment::NewLine);
						this->textField->AppendText("Enter data as an integer (4 digits max, press enter to input number):");
						this->textField->AppendText(Environment::NewLine);
						timeForUserInput = true;

						//lineNum++;
						goto endLoop;
				   }
				   else if (programAccess.getCurrentOpCode() == "11")
				   {
					   std::string output = programAccess.opWrite();
					   this->textField->AppendText(Environment::NewLine);
					   this->textField->AppendText(convertToSystemString(output));
					   //lineNum += 2;
					   programAccess.incrementPC(1);
					   continue;
				   }
				   else
				   {
					   programAccess.execute();
				   }

			   }
			   if (programAccess.getCurrentOpCode() == "43")
			   {
				   this->textBox1->Text = convertToSystemString(programAccess.getMemory());
				   this->textField->Enabled = false;
			   }
		   endLoop:;
			   //No longer able to add commands
		   }
	private: System::Void execute_Click(System::Object^ sender, System::EventArgs^ e)
	{
		try
		{
			executing = true;
			timeForUserInput = true; // set this to true so that we can look for inputs if we need to
		//programAccess.addCommand(convertFromSystemString(firstline);
		//take every line from the input window and input them into the interpreter
			cli::array<Itype>^ myLines = textField->Lines;
			for (int i = 0; i < myLines->Length;i++)
			{
				programAccess.addCommand(convertFromSystemString(myLines[i]));
			}
			this->textField->AppendText(Environment::NewLine);
			this->textField->AppendText("Halting");
			
			//now execute every line
			executeEverything();
		}
		catch (runtime_error& e)
		{
			MessageBox::Show(convertToSystemString(e.what()));
			//need everything to stop
			exit(1);
		}
	}
	private: System::Void load_Click(System::Object^ sender, System::EventArgs^ e)
	{

	}
	private: System::Void save_Click(System::Object^ sender, System::EventArgs^ e)
	{

	}
	
private: System::Void memory_content_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void listBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
}
};
}
#endif
