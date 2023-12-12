---Allows users to interact with the lower level implementations of the editor
---through a lua interface
---@class Slate
---@field mode Modes
---@field buffer Buffers
local M = {
  mode = require("mode"),
  buffer = require("buffer"),
}

return M
