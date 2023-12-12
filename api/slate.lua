---Allows users to interact with the lower level implementations of the editor
---through a lua interface
---@class Slate
---@field api Slate.Api
---@field mode Slate.Modes
---@field buffer Slate.Buffers
local M = {
  api = require("api"),
  mode = require("mode"),
  buffer = require("buffer"),
}

return M
