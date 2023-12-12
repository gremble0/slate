---Defines functions that once run will be ran by the C++ core
---@meta

---@class Slate.Api
local M = {}

-- TODO: maybe move buffer commands to separate module if slate module grows too big
---Vertically split the window, returns buffer id for new buffer
---@param bufid integer buffer to split
M.vsplit = function(bufid) end

---Horizontally split the window, returns buffer id for new buffer
---@param bufid integer buffer to split
M.hsplit = function(bufid) end

---@param bufid integer
M.set_active_buffer = function(bufid) end

---@param file_path? string path to file to open, opens empty scratch buffer if nil
M.open_buffer = function(file_path) end

---@param bufid integer id of buffer to close
M.close_buffer = function(bufid) end

---Begins visual selection at given cursor position
---@param cursor_x integer
---@param cursor_y integer
M.begin_selection = function(cursor_x, cursor_y) end

---Ends selection if active
M.end_selection = function() end

return M
