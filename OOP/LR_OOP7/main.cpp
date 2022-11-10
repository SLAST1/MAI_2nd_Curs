//
//  main.cpp
//  lab7
//  Variant 15
//  M8о-206Б-19
//  Created by Daniel Pivnitskiy on 10.10.2020.
//  github.com/SLAST1
//  Copyright © 2020 Daniel Pivnitskiy. All rights reserved.
//
/*
Спроектировать простейший «графический» векторный редактор.
Требования к реализации:
Создание графических примитивов необходимо вынести в отдельный класс – Factory.
Сделать упор на использовании полиморфизма при работе с фигурами;
Взаимодействие с пользователем (ввод команд) реализовать в функции main;
*/
#include <array>
#include <memory>
#include <vector>
#include <stack>

#include "sdl.h"
#include "imgui.h"

#include "triangle.h"
#include "hexagon.h"
#include "octagon.h"
#include "Document.h"

int main() {
	sdl::renderer renderer("Editor");
	bool quit = false;

	std::unique_ptr<builder> active_builder = nullptr;
	bool active_deleter = false;
	const int32_t file_name_length = 128;
	char file_name[file_name_length] = "";
	int32_t remove_id = 0;
	std::vector<int> color(3);

	Document currentDocument;

	while (!quit) {
		
		renderer.clear();

		sdl::event event;

		while (sdl::event::poll(event)) {
			sdl::quit_event quit_event;
			sdl::mouse_button_event mouse_button_event;
			if (event.extract(quit_event)) {
				quit = true;
				break;
			} else if (event.extract(mouse_button_event)) {
				if (active_builder && mouse_button_event.button() == sdl::mouse_button_event::left && mouse_button_event.type() == sdl::mouse_button_event::down) {
					std::unique_ptr<figure> figure = active_builder->add_vertex(vertex{mouse_button_event.x(), mouse_button_event.y()});
					if (figure) {
						figure -> setColor(color);

						currentDocument.addFigure(std::move(figure));

						active_builder = nullptr;
					}
				}
				if (active_builder && mouse_button_event.button() == sdl::mouse_button_event::right && mouse_button_event.type() == sdl::mouse_button_event::down) {
					std::unique_ptr<figure> figure = active_builder->add_vertex(vertex{-1, -1});
					if (figure) {
						figure -> setColor(color);
						
						currentDocument.addFigure(std::move(figure));

						active_builder = nullptr;
					}
				}
				
			}
		}

		currentDocument.render(renderer); 

		

		
		ImGui::Begin("Menu");
		if (ImGui::Button("New canvas")) {
			currentDocument.clear();
		}

		ImGui::InputText("File name", file_name, file_name_length - 1);

		if (ImGui::Button("Save")) {
			std::ofstream os(file_name);

			if (os) {
				currentDocument.Save(os);
			}

		}

		ImGui::SameLine();

		if (ImGui::Button("Load")) {
			std::ifstream is(file_name);

			if (is) {
				currentDocument.Load(is);
			}
				
		}


			color[0] = 255;
			color[1] = 255;
			color[2] = 255;
	
	
		if (ImGui::Button("Triangle")) {
			active_builder = std::make_unique<triangle_builder>();
		}
		if (ImGui::Button("Hexagon")) {
			active_builder = std::make_unique<hexagon_builder>();
		}
		if (ImGui::Button("Octagon")) {
			active_builder = std::make_unique<octagon_builder>();
		}

		ImGui::InputInt("Remove id", &remove_id);
		if (ImGui::Button("Remove")) {
			if (remove_id >= 0 && remove_id < (currentDocument.figures).size()) {

				currentDocument.removeFigure(remove_id);

			}
		}
		
		if (ImGui::Button("UNDO")) {

			currentDocument.undo();
		}

		ImGui::End();

		renderer.present();
	}


}
