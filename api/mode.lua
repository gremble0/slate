---Maps keybinds to a function and optionally a description
---@class KeyBind
---@field keys string
---@field command function
---@field description? string

---@class Mode
---@field keymaps table<string, KeyBind[]>

---Maps modes to an array of keybinds
---@class Modes
---@field modes table<string, Mode>
local M = {}

-- TODO: assign some default keybinds?

---Set a function to be executed upon entering the given keymap in the given mode
---@param mode string
---@param keys string
---@param command fun()
---@param desc? string
M.set_keymap = function (mode, keys, command, desc)
  local keybinds = M.modes[mode].keymaps[keys]
  keybinds[#keybinds + 1] = {
    keys = keys,
    command = command,
    description = desc
  }
end

---Removes a keymap from a mode, does not error if key is not mapped
---@param mode string
---@param keys string
M.remove_keymap = function(mode, keys)
  M.modes[mode].keymaps[keys] = nil
end

---@param mode string name of new mode
M.add_mode = function (mode)
  M.modes[mode] = { keymaps = {} }
end

return M {}
