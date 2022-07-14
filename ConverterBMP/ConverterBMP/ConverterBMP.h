#pragma once
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

typedef struct
{
	unsigned int    bfType;
	unsigned long   bfSize;
	unsigned int    bfReserved1;
	unsigned int    bfReserved2;
	unsigned long   bfOffBits;
} BITMAPFILEHEADER;

typedef struct
{
	unsigned int    biSize;
	int             biWidth;
	int             biHeight;
	unsigned short  biPlanes;
	unsigned short  biBitCount;
	unsigned int    biCompression;
	unsigned int    biSizeImage;
	int             biXPelsPerMeter;
	int             biYPelsPerMeter;
	unsigned int    biClrUsed;
	unsigned int    biClrImportant;
} BITMAPINFOHEADER;

typedef struct
{
	int   rgbBlue;
	int   rgbGreen;
	int   rgbRed;
	int   rgbReserved;
} RGBQUAD;


static unsigned short read_u16(FILE *fp);
static unsigned int   read_u32(FILE *fp);
static int            read_s32(FILE *fp);

#endif // MAIN_H_INCLUDEDs

static unsigned short read_u16(FILE *fp)
{
	unsigned char b0, b1;

	b0 = getc(fp);
	b1 = getc(fp);

	return ((b1 << 8) | b0);
}


static unsigned int read_u32(FILE *fp)
{
	unsigned char b0, b1, b2, b3;

	b0 = getc(fp);
	b1 = getc(fp);
	b2 = getc(fp);
	b3 = getc(fp);

	return ((((((b3 << 8) | b2) << 8) | b1) << 8) | b0);
}


static int read_s32(FILE *fp)
{
	unsigned char b0, b1, b2, b3;

	b0 = getc(fp);
	b1 = getc(fp);
	b2 = getc(fp);
	b3 = getc(fp);

	return ((int)(((((b3 << 8) | b2) << 8) | b1) << 8) | b0);
}
namespace ConverterBMP {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Runtime::InteropServices;
	/// <summary>
	/// Summary for ConverterBMP
	/// </summary>
	public ref class ConverterBMP : public System::Windows::Forms::Form
	{
	public:
		ConverterBMP(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ConverterBMP()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button3;
	protected:
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Label^  label3;



	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  label1;



	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button3->Location = System::Drawing::Point(219, 186);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(185, 30);
			this->button3->TabIndex = 15;
			this->button3->Text = L"Бинарный файл";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &ConverterBMP::button3_Click);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->Location = System::Drawing::Point(219, 150);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(185, 30);
			this->button2->TabIndex = 14;
			this->button2->Text = L"Текстовый файл";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &ConverterBMP::button2_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(24, 167);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(149, 20);
			this->label3->TabIndex = 13;
			this->label3->Text = L"Конвертировать в";
			// 
			// button1
			// 
			this->button1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(219, 69);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(104, 30);
			this->button1->TabIndex = 9;
			this->button1->Text = L"Открыть";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &ConverterBMP::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(61, 69);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(87, 20);
			this->label1->TabIndex = 8;
			this->label1->Text = L"Файл bmp";
			// 
			// ConverterBMP
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(429, 265);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Name = L"ConverterBMP";
			this->Text = L"ConverterBMP";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &ConverterBMP::ConverterBMP_FormClosing);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		int width;
		int height;
		const char* bmpfilename;
		FILE *bmpfile;
		FILE *txtfile;
		FILE *binfile;
		OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog;

	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		if (bmpfile != NULL) {
			if (fseek(bmpfile, 0, SEEK_SET) != 0)
				MessageBox::Show("Ошибка открытия bmp файла");
			else {
				// заголовок файла
				BITMAPFILEHEADER header[[gnu::unused]];

				header.bfType = read_u16(bmpfile);
				header.bfSize = read_u32(bmpfile);
				header.bfReserved1 = read_u16(bmpfile);
				header.bfReserved2 = read_u16(bmpfile);
				header.bfOffBits = read_u32(bmpfile);

				//заголовок изображения
				BITMAPINFOHEADER bmiHeader;

				bmiHeader.biSize = read_u32(bmpfile);
				bmiHeader.biWidth = read_s32(bmpfile);
				bmiHeader.biHeight = read_s32(bmpfile);
				bmiHeader.biPlanes = read_u16(bmpfile);
				bmiHeader.biBitCount = read_u16(bmpfile);
				bmiHeader.biCompression = read_u32(bmpfile);
				bmiHeader.biSizeImage = read_u32(bmpfile);
				bmiHeader.biXPelsPerMeter = read_s32(bmpfile);
				bmiHeader.biYPelsPerMeter = read_s32(bmpfile);
				bmiHeader.biClrUsed = read_u32(bmpfile);
				bmiHeader.biClrImportant = read_u32(bmpfile);

				width = bmiHeader.biWidth;
				height = bmiHeader.biHeight;
				//коды цвета
				RGBQUAD **rgb = new RGBQUAD*[bmiHeader.biWidth];
				for (int i = 0; i < bmiHeader.biWidth; i++) {
					rgb[i] = new RGBQUAD[bmiHeader.biHeight];
				}

				for (int i = 0; i < bmiHeader.biWidth; i++) {
					for (int j = 0; j < bmiHeader.biHeight; j++) {
						rgb[i][j].rgbBlue = getc(bmpfile);
						rgb[i][j].rgbGreen = getc(bmpfile);
						rgb[i][j].rgbRed = getc(bmpfile);
					}
				}

				SaveFileDialog^ saveFileDialogtxt = gcnew SaveFileDialog;
				saveFileDialogtxt->Filter = "txt files (*.txt)|*.txt|All files (*.*)|*.*";
				if (saveFileDialogtxt->ShowDialog() == System::Windows::Forms::DialogResult::OK)
				{
					String^ fileNametxt = saveFileDialogtxt->FileName;
					const char* txtfilename;
					IntPtr p = Marshal::StringToHGlobalAnsi(fileNametxt);
					txtfilename = static_cast<const char*>(p.ToPointer());


					if ((txtfile = fopen(txtfilename, "w")) != NULL) {
						// запись в txt
						fprintf(txtfile, "unsigned char image_map[] = {\n#if LV_COLOR_DEPTH == 24\n");

						for (int i = width - 1; i >= 0; i--) {
							for (int j = 0; j < height; j++) {
								fprintf(txtfile, "0x%02x, 0x%02x, 0x%02x, ", rgb[i][j].rgbBlue, rgb[i][j].rgbGreen, rgb[i][j].rgbRed);
							}
							fprintf(txtfile, "\n");
						}
						fprintf(txtfile, "\n#endif\n};");
						fclose(txtfile);
						for (int i = 0; i < width; ++i)
							delete[] rgb[i];
						delete[] rgb;
					}
					else MessageBox::Show("Ошибка открытия текстового файла");
				}
			}
		}
		else MessageBox::Show("Ошибка открытия bmp файла");

	}

	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {

		SaveFileDialog^ saveFileDialogbin = gcnew SaveFileDialog;
		saveFileDialogbin->Filter = "bin files (*.bin)|*.bin|All files (*.*)|*.*";
		if (saveFileDialogbin->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			String^ fileNamebin = saveFileDialogbin->FileName;
			const char* binfilename;
			IntPtr p = Marshal::StringToHGlobalAnsi(fileNamebin);
			binfilename = static_cast<const char*>(p.ToPointer());

			//запись в bin
			if ((binfile = fopen(binfilename, "w")) != NULL) {
				char buffer[BUFSIZ];
				int nread = 0;
				if (fseek(bmpfile, 54, SEEK_SET) != 0)
					MessageBox::Show("Ошибка открытия bmp файла");
				else {
					while (nread = fread(buffer, sizeof(char), sizeof(buffer), bmpfile)) {
						fwrite(buffer, sizeof(char), nread, binfile);
					}
					fclose(binfile);
				}
			}
			else MessageBox::Show("Ошибка открытия бинарного файла");
		}
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

		openFileDialog1->Filter = "bmp files (*.bmp)|*.bmp|All files (*.*)|*.*";
		openFileDialog1->FilterIndex = 2;
		openFileDialog1->RestoreDirectory = true;

		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			String^ a = openFileDialog1->FileName;
			IntPtr p = Marshal::StringToHGlobalAnsi(a);
			bmpfilename = static_cast<const char*>(p.ToPointer());
			if ((bmpfile = fopen(bmpfilename, "rb")) == NULL)
				MessageBox::Show("Ошибка открытия bmp файла");
		}

	}
	private: System::Void ConverterBMP_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
		if (bmpfile != NULL)
			fclose(bmpfile);
	}
	};
}
