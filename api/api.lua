require("mode")

---Allows users to interact with the lower level implementations of the editor
---through a lua interface
---@class slate
---@field active_bufid integer
---@field open_bufs integer[]
---@field visible_bufs integer[]
local M = {}

---Set a function to be executed upon entering the given keymap in the given mode
---@param mode Mode
---@param keys string
---@param command fun()
---@param desc? string
M.set_keymap = function (mode, keys, command, desc)
  mode.keymap[keys] = { command, desc }
end

---@param mode Mode
---@param keys string
M.remove_keymap = function(mode, keys)
  mode.keymap[keys] = nil
end

-- TODO: maybe move buffer commands to separate module if slate module grows too big
---Vertically split the window
M.vsplit = function() end

---Horizontally split the window
M.hsplit = function() end

---@param bufid integer
M.set_active_buffer = function(bufid)
  M.active_bufid = bufid
end

---@param file_path? string path to file to open, opens empty scratch buffer if nil
M.open_buffer = function(file_path) end

---@param bufid integer id of buffer to close
M.close_buffer = function(bufid) end

---Begins visual selection at given cursor position
---@param cursor_x integer
---@param cursor_y integer
M.begin_selection = function(cursor_x, cursor_y) end

M.end_selection = function() end

return M
