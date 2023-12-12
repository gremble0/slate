local api = require("api")

---@class Cursor
---@field x integer
---@field y integer

---@class Buffer
---@field id integer
---@field name string
---@field cursor Cursor
---@field lines string[]
---@field n_lines integer

---Friendlier interface containing 
---@class Slate.Buffers
---@field open_bufs Buffer[]
---@field active_buf Buffer
local M = {}

-- TODO: maybe move buffer commands to separate module if slate module grows too big
---Vertically split the active buffer
M.vsplit = function()
  local new_buf = { ---@class Buffer
    id = #M.open_bufs + 1,
    name = M.active_buf.name,
    cursor = { x = 0, y = 0 },
    lines = M.active_buf.lines,
  }
  M.open_bufs[#M.open_bufs + 1] = new_buf
  M.active_buf = new_buf

  api.vsplit(M.active_buf.id)
end

---Horizontally split the active buffer
M.hsplit = function()
  local new_buf = { ---@class Buffer
    id = #M.open_bufs + 1,
    name = M.active_buf.name,
    cursor = { x = 0, y = 0 },
    lines = M.active_buf.lines,
  }
  M.open_bufs[#M.open_bufs + 1] = new_buf
  M.active_buf = new_buf

  api.hsplit(M.active_buf.id)
end

---@param bufid integer
M.set_active_buffer = function(bufid)
  for _, buf in ipairs(M.open_bufs) do
    if buf.id == bufid then
      M.active_buf = buf
      -- TODO: some api calls
    end
  end
end

---@param file_path? string path to file to open, opens empty scratch buffer if nil
M.open_buffer = function(file_path)
  if file_path == nil then
    local new_buf = {
      id = #M.open_bufs + 1,
      name = "*scratch*",
    }
  end

  M.active_buf = #M.open_bufs + 1
  M.open_bufs[#M.open_bufs + 1] = M.active_buf
  api.open_buffer(file_path)
end

---@param bufid integer id of buffer to close, 0 for active buffer
M.close_buffer = function(bufid) end

---Begins visual selection at given cursor position
---@param cursor_x integer
---@param cursor_y integer
M.begin_selection = function(cursor_x, cursor_y) end

---Ends selection if active
M.end_selection = function() end

return M
