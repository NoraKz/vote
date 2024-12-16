#include <string>

namespace ui {
    std::string IndexHTML = R"INDEXHTML(
<html>
<head>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <link href="https://unpkg.com/layui@2.9.20/dist/css/layui.css" rel="stylesheet">
</head>
<body>
  <script src="https://unpkg.com/layui@2.9.20/dist/layui.js"></script>
  <script>
    function aboutShow()
    {
      layer.msg("程设结课项目 - vote\n软国2407 丁励治 马玉灏 郭斯瀚 龚炜程");
    }
  </script>
  <div style="margin: 15px;">
    <button class="layui-btn" onclick="window.changeToVote()">抽签!</button>
    <button class="layui-btn" onclick="window.changeToStudent()">管理学生名单</button>
    <br>
    <br>
    <button class="layui-btn layui-btn-primary layui-border-blue" onclick="aboutShow()">关于</button>
    <br>
    <br>
    <div style="text-align: center;" class="layui-text-em">
        vote &copy;软国2407 丁励治 马玉灏 郭斯瀚 龚炜程
    </div>
  </div>
</body>
</html>
)INDEXHTML";
}