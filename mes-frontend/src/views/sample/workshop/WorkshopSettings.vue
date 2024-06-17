<template>
  <div>
    <!-- 表单 -->
    <el-row :gutter="20">
      <el-col :span="5">
        <el-form :inline="true" size="small">
          <el-form-item label="车间编码">
            <el-input
              placeholder="请输入车间编码"
              v-model="form.workshopCode"
              style="width: 185px"
            ></el-input>
          </el-form-item>
        </el-form>
      </el-col>
      <el-col :span="5">
        <el-form :inline="true" size="small">
          <el-form-item label="车间名称">
            <el-input
              placeholder="请输入车间名称"
              v-model="form.workshopName"
              style="width: 185px"
            ></el-input>
          </el-form-item>
        </el-form>
      </el-col>
      <el-col :span="4" class="button-col">
        <el-form :inline="true" size="small">
          <el-form-item>
            <el-button type="primary" @click="search">搜索</el-button>
            <el-button @click="reset">重置</el-button>
          </el-form-item>
        </el-form>
      </el-col>
    </el-row>

    <!-- 按钮组 -->
    <el-row :gutter="20" style="margin-top: 10px">
      <el-col :span="20">
        <el-button type="success" size="small" @click="add">新增</el-button>
        <el-button
          type="warning"
          size="small"
          @click="edit"
          :disabled="!hasSelection"
        >修改</el-button>
        <el-button
          type="danger"
          size="small"
          @click="deleteSelected"
          :disabled="!hasSelection"
        >删除</el-button>
        <el-button type="info" size="small" @click="exportData">导出</el-button>
      </el-col>
    </el-row>

    <!-- 表格 -->
    <el-table
      :data="paginatedData"
      border
      stripe
      style="margin-top: 20px"
      @selection-change="handleSelectionChange"
    >
      <el-table-column type="selection" width="55"></el-table-column>
      <el-table-column prop="workshopCode" label="车间编码" width="150"></el-table-column>
      <el-table-column prop="workshopName" label="车间名称" width="150"></el-table-column>
      <el-table-column prop="area" label="面积" width="100"></el-table-column>
      <el-table-column prop="manager" label="负责人" width="100"></el-table-column>
      <el-table-column prop="isEnabled" label="是否启用" width="100">
        <template #default="scope">
          <span class="status" :class="scope.row.isEnabled ? 'enabled' : 'disabled'">
            {{ scope.row.isEnabled ? '是' : '否' }}
          </span>
        </template>
      </el-table-column>
      <el-table-column prop="remarks" label="备注" width="180"></el-table-column>
      <el-table-column label="操作" width="180">
        <template #default="scope">
          <el-button link type="primary" size="small" @click.prevent="handleEdit(scope.row)">修改</el-button>
          <el-button link type="primary" size="small" @click.prevent="deleteSingleRow(scope.row)">删除</el-button>
        </template>
      </el-table-column>
    </el-table>

    <!-- 分页 -->
    <el-pagination
      background
      layout="prev, pager, next"
      :total="tableData.length"
      :page-size="pageSize"
      @current-change="handlePageChange"
      style="margin-top: 20px"
    ></el-pagination>

    <!-- 引入的弹窗 -->
    <el-dialog v-model="dialogVisible" :title="dialogTitle" width="500px">
      <el-form :model="formModel" label-width="100px">
        <el-form-item label="车间编码">
          <el-input v-model="formModel.workshopCode"></el-input>
        </el-form-item>
        <el-form-item>
          <el-button @click="generateWorkshopCode">自动生成</el-button>
        </el-form-item>
        <el-form-item label="车间名称">
          <el-input v-model="formModel.workshopName"></el-input>
        </el-form-item>
        <el-form-item label="面积">
          <el-input v-model="formModel.area" placeholder="请输入面积大小"></el-input>
        </el-form-item>
        <el-form-item label="负责人">
          <el-input v-model="formModel.manager"></el-input>
        </el-form-item>
        <el-form-item label="是否启用">
          <el-switch v-model="formModel.isEnabled"></el-switch>
        </el-form-item>
        <el-form-item label="备注">
          <el-input v-model="formModel.remarks"></el-input>
        </el-form-item>
      </el-form>
      <template #footer>
        <div class="dialog-footer">
          <el-button @click="dialogVisible = false">取消</el-button>
          <el-button type="primary" @click="onSubmit">确定</el-button>
        </div>
      </template>
    </el-dialog>
  </div>
</template>

<script lang="ts" setup>
import { ref, computed } from 'vue';
import { ElMessage } from 'element-plus';

const dialogVisible = ref(false);
const dialogTitle = ref('添加');
const formModel = ref({
  workshopCode: '',
  workshopName: '',
  area: '',
  manager: '',
  isEnabled: false,
  remarks: '',
});
const form = ref({
  workshopCode: '',
  workshopName: '',
});
const tableData = ref([
  { workshopCode: '001', workshopName: '车间1', area: '1000', manager: '张三', isEnabled: true, remarks: '备注1' },
  { workshopCode: '002', workshopName: '车间2', area: '800', manager: '李四', isEnabled: false, remarks: '备注2' },
  { workshopCode: '003', workshopName: '车间3', area: '1200', manager: '王五', isEnabled: true, remarks: '备注3' },
  { workshopCode: '004', workshopName: '车间4', area: '1500', manager: '赵六', isEnabled: false, remarks: '备注4' },
]);

const selectedItems = ref([]);
const currentPage = ref(1);
const pageSize = ref(10);

const paginatedData = computed(() => {
  const start = (currentPage.value - 1) * pageSize.value;
  const end = currentPage.value * pageSize.value;
  return tableData.value.slice(start, end);
});

const hasSelection = computed(() => {
  return selectedItems.value.length > 0;
});

const search = () => {
  // 搜索逻辑
};

const reset = () => {
  form.value.workshopCode = '';
  form.value.workshopName = '';
};

const add = () => {
  dialogTitle.value = '添加';
  dialogVisible.value = true;
  formModel.value = {
    workshopCode: generateWorkshopCode(),
    workshopName: '',
    area: '',
    manager: '',
    isEnabled: false,
    remarks: '',
  };
};

const edit = () => {
  if (selectedItems.value.length === 1) {
    dialogTitle.value = '修改';
    dialogVisible.value = true;
    formModel.value = { ...selectedItems.value[0] };
  } else {
    ElMessage.warning('请选择一项进行编辑');
  }
};

const deleteSelected = () => {
  selectedItems.value.forEach((item) => {
    const index = tableData.value.indexOf(item);
    if (index > -1) {
      tableData.value.splice(index, 1);
    }
  });
  ElMessage.success('删除成功');
};

const deleteSingleRow = (row) => {
  const index = tableData.value.indexOf(row);
  if (index > -1) {
    tableData.value.splice(index, 1);
  }
  ElMessage.success('删除成功');
};

const exportData = () => {
  // 导出逻辑
};

const handleEdit = (row) => {
  dialogTitle.value = '修改';
  dialogVisible.value = true;
  formModel.value = { ...row };
};

const handleSelectionChange = (val) => {
  selectedItems.value = val;
};

const handlePageChange = (page) => {
  currentPage.value = page;
};

const generateWorkshopCode = () => {
  const randomCode = 'WS' + Math.floor(Math.random() * 900 + 100);
  formModel.value.workshopCode = randomCode;
  return randomCode;
};

const onSubmit = () => {
  if (dialogTitle.value === '添加') {
    tableData.value.push({ ...formModel.value });
    ElMessage.success('添加成功');
  } else if (dialogTitle.value === '修改') {
    const index = tableData.value.findIndex(
      (item) => item.workshopCode === formModel.value.workshopCode,
    );
    if (index !== -1) {
      tableData.value[index] = { ...formModel.value };
      ElMessage.success('修改成功');
    }
  }
  dialogVisible.value = false;
};
</script>

<style scoped>
.form-inline {
  margin-bottom: 10px;
}

.button-group {
  margin-bottom: 10px;
}

.dialog-footer {
  text-align: right;
}

.button-col .el-form-item {
  margin-right: 10px; /* 增加表单和按钮之间的间距 */
}

.status {
  display: inline-block;
  padding: 2px 5px;
  border-radius: 3px;
  color: #409eff;
  border: 1px solid #409eff;
}

.status.enabled {
  background-color: #409eff;
  color: white;
}

.status.disabled {
  background-color: #e0e0e0;
  color: #b0b0b0;
}

.el-button[disabled] {
  cursor: not-allowed !important;
}

</style>
