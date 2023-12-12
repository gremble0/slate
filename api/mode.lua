---Maps keys to a function and optionally a description
---@class Command
---@field fun function
---@field description? string

---Maps keys to commands
---@class Mode
---@field name string
---@field commands table<string, Command>

---Maps modes to an array of keybinds
---@class Modes
---@field active_mode Mode
---@field modes Mode[]
local M = {}

-- TODO: assign some default keybinds?

---Set a function to be executed upon entering the given keymap in the given mode
---@param mode string
---@param keys string
---@param command fun()
---@param desc? string
M.set_keymap = function (mode, keys, command, desc)
  for _, m in pairs(M.modes) do
    if m.name == mode then
      m.commands[keys] = {
        fun = command,
        description = desc,
      }
    end
  end
end

---Removes a keymap from a mode, does not error if key is not mapped
---@param mode string
---@param keys string
M.remove_keymap = function(mode, keys)
  for _, m in pairs(M.modes) do
    if m.name == mode then
      m.commands[keys] = nil
    end
  end
end

---Adds a mode with no keybinds
---@param mode string name of new mode
M.add_mode = function (mode)
  for _, m in pairs(M.modes) do
    if m.name == mode then
      error("Cannot create mode that already exists")
    end
  end

  M.modes[#M.modes + 1] = {
    name = mode,
    commands = {},
  }
end

return M {}
