#pragma once

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
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;

	protected:

	private:
		/// <summary>
		/// Erforderliche Designervariable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode für die Designerunterstützung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
		/// </summary>
		void InitializeComponent(void)
		{
			this->textField = (gcnew System::Windows::Forms::TextBox());
			this->pageSetupDialog1 = (gcnew System::Windows::Forms::PageSetupDialog());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// textField
			// 
			this->textField->Location = System::Drawing::Point(12, 12);
			this->textField->Multiline = true;
			this->textField->Name = L"textField";
			this->textField->Size = System::Drawing::Size(138, 219);
			this->textField->TabIndex = 1;
			this->textField->TextChanged += gcnew System::EventHandler(this, &Form1::textField_TextChanged);
			this->textField->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::textField_KeyDown);
			this->textField->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::textField_KeyPress);
			this->textField->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::textField_KeyUp);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(12, 247);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(106, 37);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Help";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(192, 247);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(105, 37);
			this->button2->TabIndex = 3;
			this->button2->Text = L"Run/Halt";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(380, 247);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(104, 37);
			this->button3->TabIndex = 4;
			this->button3->Text = L"Log";
			this->button3->UseVisualStyleBackColor = true;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(560, 305);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textField);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	bool nonNumberEntered = false;
	int lineNum = 0;
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
					if (e->KeyCode != Keys::Enter)
					{
						if (Control::ModifierKeys == Keys::Shift) {
							if (e->KeyCode != Keys::Add)
							{
								// A non-numerical keystroke was pressed.
								// Set the flag to true and evaluate in KeyPress event.
								nonNumberEntered = true;
							}
						}
					}
					if (e->KeyCode == Keys::Enter)
					{	
						array<String^>^ myLines = textField->Lines;
						String^ firstline = myLines[lineNum];
						MessageBox::Show(firstline);
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
						
						lineNum++;
					}
				}
			}
		}



	}
private: System::Void textField_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
	if (nonNumberEntered == true)
	{
		// Stop the character from being entered into the control since it is non-numerical.
		e->Handled = true;
	}
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
