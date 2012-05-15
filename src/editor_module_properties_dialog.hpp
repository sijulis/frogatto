#ifndef EDITOR_MODULE_PROPERTIES_DIALOG_HPP_INCLUDED
#define EDITOR_MODULE_PROPERTIES_DIALOG_HPP_INCLUDED
#ifndef NO_EDITOR


#include <string>
#include <vector>

#include "dialog.hpp"
#include "module.hpp"

class editor;

namespace editor_dialogs
{

class editor_module_properties_dialog : public gui::dialog
{
public:
	explicit editor_module_properties_dialog(editor& e);
	explicit editor_module_properties_dialog(editor& e, const std::string& modname);
	void init();
	const std::string on_exit();
private:
	void change_id();
	void change_name();
	void change_prefix();
	void change_module_includes();
	void remove_module_include(const std::string& s);
	void execute_change_module_includes(const std::vector<std::string>& choices, int index);
	void save_module_properties();
	void create_new_module();

	bool new_mod_;
	editor& editor_;
	gui::widget_ptr context_menu_;
	module::modules mod_;
	std::vector<std::string> loaded_mod_;
	std::vector<std::string> dirs_;
};

}

#endif // !NO_EDITOR
#endif
