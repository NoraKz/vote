#include <string>

namespace ui {
    std::string StudentHTML = R"HTML(
<html>
<head>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <link href="https://unpkg.com/layui@2.9.20/dist/css/layui.css" rel="stylesheet">
</head>
<body>
  <script src="https://unpkg.com/vue@3/dist/vue.global.js"></script>
  <script src="https://unpkg.com/layui@2.9.20/dist/layui.js"></script>
    <div id="app">
        <div style="margin: 15px;">
            <button class="layui-btn" onclick="window.changeToIndex()">返回主页</button>
            <br>
            <br>
            <div class="layui-form">
                <select lay-filter="class-select-filter">
                  <option value="">请选择</option>
                  <option value="">请选择</option>
                </select>
            </div>
            <br>
            <button class="layui-btn" @click="loadData">加载</button>
            <button class="layui-btn layui-btn-normal" @click="addClass">新建班级</button>
        </div>
    </div>

    <script>
    let selectClass = "";
    const { createApp } = Vue
  
    createApp({
        data() {
          return {
            classList: []
        }},
        methods: {
            loadData()
            {
                console.info(selectClass);
            },
            addClass()
            {
                layer.prompt({title: '请输入要添加的班级名（例如软国2407）：'}, function(value, index, elem){
                    if(value === '') return elem.focus();
                    window.addClass(value);
                    layer.msg("添加成功！");
                    layer.close(index);
                });
            },
            async loadClass()
            {
                var i = await window.getClass();
                this.classList = i.data;
                console.info(this.classList);
            }
        },
        mounted() {
            this.loadClass();
        }
    }).mount('#app');

    layui.use(function(){

var form = layui.form;
var layer = layui.layer;
form.on('select(class-select-filter)', function(data){
  var value = data.value;
  selectClass = value;
});
});
</script>
</body>
</html>
)HTML";
}