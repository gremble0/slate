---@class Buffers
---@field active_bufid integer
---@field open_bufs integer[]
---@field visible_bufs integer[]
local M = {}

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
