#include "imgui.h"
#include "imguiwrap.dear.h"
#include "imguiwrap.helpers.h"

ImGuiWrapperReturnType
gui_main()
{
	static ImGuiWindowFlags windowFlags {
		ImGuiWindowFlags_AlwaysAutoResize |
		ImGuiWindowFlags_NoSavedSettings
	};
	static ImGuiTableFlags tableFlags {
		ImGuiTableFlags_SizingStretchSame |
		ImGuiTableFlags_Borders
	};
	dear::Begin("Grid", nullptr, windowFlags) && []() {
		dear::EditWindowFlags("Window Flags", nullptr, &windowFlags);
		dear::EditTableFlags("Table Flags", nullptr, &tableFlags);
		constexpr size_t maxDim = 10;

		dear::Table("#grid", maxDim, tableFlags) && []() {
			for (size_t y = 0; y < maxDim; y++) {
				if (y > 0)
					ImGui::TableNextRow();
				for (size_t x = 0; x < maxDim; x++) {
					if (y < 4 && x < 6) {
						ImGui::TableNextColumn();
						char value[3];
						snprintf(value, sizeof(value), "%02X", (int)x * 16 + (int)y);
						ImGui::Selectable(value);
						if (x == 3 && y == 3) {
							ImGui::TextUnformatted("*1");
						}
					}
				}
			}
		};
	};

	return {};
}

int main()
{
	imgui_main(ImGuiWrapConfig{}, gui_main);
}
